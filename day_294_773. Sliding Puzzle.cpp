/*
773. Sliding Puzzle
Solved
Hard
Topics
Companies
Hint
On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

 

Example 1:


Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Example 2:


Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Example 3:


Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
 

Constraints:

board.length == 2
board[i].length == 3
0 <= board[i][j] <= 5
Each value board[i][j] is unique.
*/

/*
Approach:
1. The problem involves solving a sliding puzzle using Breadth-First Search (BFS).
2. The board is 2x3, with numbers from 1 to 5 and an empty space represented by 0.
3. The goal is to find the minimum number of moves to transform the board into the target configuration "123450".
4. Each state of the board is represented as a string. We use BFS to explore all possible moves level by level until the target configuration is found.

Steps:
1. Convert the 2x3 board into a string for easier manipulation.
2. Use BFS to explore each possible board state starting from the initial configuration.
3. Track each board configuration to avoid revisiting states using a set.
4. For each state, identify the position of '0' (empty space) and explore all possible swaps using predefined neighbors.
5. If the target state is reached, return the number of moves (levels). If the queue is exhausted without reaching the target, return -1.

Time Complexity:
- O(V + E), where V is the number of possible states (6! = 720) and E is the edges (number of moves possible from each state).
- In practice, this is manageable due to the limited size of the 2x3 board.

Space Complexity:
- O(V) to store the visited states and the queue.

*/

class Solution {
public:
    // Function to solve the sliding puzzle problem
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";

        // Convert 2x3 board to a string for easy manipulation
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }

        string target = "123450";  // Target configuration
        unordered_map<int, vector<int>> mp; // Map to store possible swaps
        // Defining the neighbors for each index in the 2x3 board
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        unordered_set<string> visited; // Set to track visited states
        visited.insert(start);
        
        queue<string> q;
        q.push(start);

        int level = 0; // BFS level (number of moves)

        // BFS to explore all possible states
        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                string curr = q.front();
                q.pop();

                // Check if the target configuration is reached
                if(curr == target) {
                    return level;
                }

                // Find the index of '0' (empty space)
                int zeroIndex = curr.find('0');

                // Explore all possible swaps for the current '0' position
                for(int &swapIdx : mp[zeroIndex]) {
                    string newState = curr;
                    swap(newState[zeroIndex], newState[swapIdx]);

                    // If the new state hasn't been visited, add to the queue
                    if(visited.find(newState) == visited.end()) {
                        q.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            level++; // Increment level after processing all nodes at the current depth
        }

        return -1; // Return -1 if the target configuration is not reachable
    }
};
