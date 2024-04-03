/*
79. Word Search
Solved
Medium
Topics
Companies
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 
*/

/**
 * Intuition:
 * This problem can be solved using a backtracking approach where we start exploring the board from each cell. 
 * We recursively search for the word in the board by exploring all possible directions from each cell.
 * If we find the word, we return true, otherwise, we backtrack and explore other paths.
 * We mark the cells visited to avoid revisiting them in the current search path.
 * If the length of the word exceeds the number of cells in the board, it's not possible to find the word.
 * 
 * Time Complexity: O(m * n * 4^l)
 * - m and n are the dimensions of the board.
 * - l is the length of the word.
 * - We explore four directions from each cell and perform backtracking, resulting in a time complexity of O(4^l) for each cell.
 * - Overall, we explore each cell in the board, resulting in a time complexity of O(m * n * 4^l).
 * 
 * Space Complexity: O(l)
 * - We use recursion to search for the word, which requires additional space proportional to the length of the word.
 * - The recursive call stack can have at most 'l' frames.
 * - Hence, the space complexity is O(l).
 */

class Solution {
public:
    int l, m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    // Function to recursively search for the word in the board
    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx) {
        // Base case: if the current index exceeds the length of the word, return true
        if(idx >= l)
            return true;
        
        // Base case: if the current cell is out of bounds or doesn't match the current character of the word, return false
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$'; // Mark the cell as visited
        
        // Explore all four directions from the current cell
        for(auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            // Recursively search in the next cell with the next character of the word
            if(find(board, new_i, new_j, word, idx+1))
                return true;
        }
        
        board[i][j] = temp; // Backtrack: restore the original value of the cell
        return false;
    }
    
    // Main function to check if the word exists in the board
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.length();
        
        // If the length of the word exceeds the number of cells in the board, it's not possible to find the word
        if(m*n < l)
            return false;
        
        // Start exploring the board from each cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // If the current cell matches the first character of the word, start searching for the word
                if(board[i][j] == word[0] && find(board, i, j, word, 0)) {
                    return true; // If the word is found, return true
                }
            }
        }
        
        return false; // If the word is not found in any cell, return false
    }
};