/*
1105. Filling Bookcase Shelves
Solved
Medium
Topics
Companies
Hint
You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

 

Example 1:


Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.
Example 2:

Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
Output: 4
 

Constraints:

1 <= books.length <= 1000
1 <= thicknessi <= shelfWidth <= 1000
1 <= heighti <= 1000
*/

/*
Intuition:
The problem is about placing books on shelves with a fixed width to minimize the total height of the shelves. For each book, we have two choices: either place it on the current shelf or start a new shelf. The solution uses dynamic programming (DP) to explore these choices and find the minimum height arrangement.

Time Complexity:
The time complexity is O(n * w), where n is the number of books and w is the shelf width. This is because we explore each book's placement for each possible remaining width.

Space Complexity:
The space complexity is also O(n * w), due to the DP table storing results for each book index and remaining width.

*/

class Solution {
private:
    int width; // Maximum shelf width
    vector<vector<int>> dp; // DP table to store intermediate results

public:
    // Recursive function to find the minimum height of the shelves
    int solve(vector<vector<int>>& books, int i, int n, int remWidth, int currHeight) {
        if (i == n) {
            return currHeight; // Return the current shelf height if all books are processed
        }

        // If result is already computed, return it
        if(dp[i][remWidth] != -1){
            return dp[i][remWidth];
        }

        int bookW = books[i][0]; // Width of the current book
        int bookH = books[i][1]; // Height of the current book

        // Option 1: Keep the current book on the same shelf
        int keep = INT_MAX;
        if (bookW <= remWidth) {
            keep = solve(books, i + 1, n, remWidth - bookW, max(currHeight, bookH));
        }

        // Option 2: Place the current book on a new shelf
        int skip = currHeight + solve(books, i + 1, n, width - bookW, bookH);

        // Store and return the minimum height result for this state
        return dp[i][remWidth] = min(keep, skip);
    }

    // Main function to calculate the minimum height of bookshelves
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        width = shelfWidth;
        int n = books.size();
        dp = vector<vector<int>>(n, vector<int>(shelfWidth + 1, -1));
        return solve(books, 0, n, shelfWidth, 0);
    }
};
