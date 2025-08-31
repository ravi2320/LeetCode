/*
3446. Sort Matrix by Diagonals
Solved

avatar
Discuss Approach
arrow-up
Medium
Topics
premium lock icon
Companies
Hint
You are given an n x n square matrix of integers grid. Return the matrix such that:

The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
The diagonals in the top-right triangle are sorted in non-decreasing order.
 

Example 1:

Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

Output: [[8,2,3],[9,6,7],[4,5,1]]

Explanation:



The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:

[1, 8, 6] becomes [8, 6, 1].
[9, 5] and [4] remain unchanged.
The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:

[7, 2] becomes [2, 7].
[3] remains unchanged.
Example 2:

Input: grid = [[0,1],[1,2]]

Output: [[2,1],[1,0]]

Explanation:



The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to [2, 0]. The other diagonals are already in the correct order.

Example 3:

Input: grid = [[1]]

Output: [[1]]

Explanation:

Diagonals with exactly one element are already in order, so no changes are needed.

 

Constraints:

grid.length == grid[i].length == n
1 <= n <= 10
-105 <= grid[i][j] <= 105
*/

/*
Approach:
1. Use a hash map `mp` where key = (i - j), which uniquely identifies each diagonal in the matrix.  
   - Positive (i - j) → diagonals below the main diagonal.  
   - Negative (i - j) → diagonals above the main diagonal.  
   - Zero → the main diagonal.
2. Traverse the matrix and push each element into the corresponding diagonal bucket in `mp`.
3. Sort each diagonal individually:
   - If key < 0 (above main diagonal) → sort in descending order.
   - If key >= 0 (main or below) → sort in ascending order.
4. Reassign sorted values back into the matrix by popping from the diagonal vectors.

Intuition:
- The difference `(i - j)` uniquely identifies diagonals.  
- Sorting per diagonal independently ensures the matrix maintains diagonal ordering constraints.  
- Sorting direction depends on position relative to the main diagonal.

Time Complexity:
- Collecting elements into map: O(n²).  
- Sorting each diagonal: total O(n² log n) in worst case (since sum of all diagonal elements = n²).  
- Refilling grid: O(n²).  
=> Overall: **O(n² log n)**

Space Complexity:
- Extra storage for map of diagonals: O(n²).  
=> Overall: **O(n²)**.
*/

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Map to store diagonals identified by (i-j)
        unordered_map<int, vector<int>> mp;

        // Step 1: Collect elements from each diagonal into the map
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mp[i - j].push_back(grid[i][j]);
            }
        }

        // Step 2: Sort each diagonal
        for(auto &itr : mp){
            if(itr.first < 0){
                // Above main diagonal → descending order
                sort(itr.second.rbegin(), itr.second.rend());
            }
            else{
                // On or below main diagonal → ascending order
                sort(itr.second.begin(), itr.second.end());
            }
        }

        // Step 3: Put back sorted elements into grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = mp[i - j].back(); // take the last element
                mp[i - j].pop_back();          // remove it from vector
            }
        }

        return grid;
    }
};
