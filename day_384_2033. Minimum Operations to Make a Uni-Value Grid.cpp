/*
2033. Minimum Operations to Make a Uni-Value Grid
Solved
Medium
Topics
Companies
Hint
You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

 

Example 1:


Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
Example 2:


Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.
Example 3:


Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
1 <= x, grid[i][j] <= 104
*/

/*
    🔹 Approach:
    - Convert the 2D `grid` into a **1D array**.
    - Sort the array to find the **median** (optimal target value).
    - Compute the number of operations needed to make all elements equal to the median.
    - If any number has a remainder different from `target % x`, return `-1` (impossible case).

    🔹 Intuition:
    - To minimize operations, the best choice for the target value is the **median** of the sorted array.
    - Since all numbers should be transformed to the target using `x` increments/decrements, check if transformation is possible.
    
    🔹 Time Complexity:
    - **O(M * N log (M * N))** → Sorting the `M * N` elements dominates.
    
    🔹 Space Complexity:
    - **O(M * N)** → To store the flattened grid in `vec`.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();

        vector<int> vec;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vec.push_back(grid[i][j]); // Flatten the grid into a 1D array
            }
        }

        int L = m * n;
        sort(vec.begin(), vec.end()); // Sort the array

        int target = vec[L / 2]; // Select the median as the target value

        int res = 0;
        for (int &num : vec) {
            if (num % x != target % x) {
                return -1; // If any number is incompatible with `x` steps, return impossible
            }
            res += abs(target - num) / x; // Count steps needed to transform `num` to `target`
        }

        return res;
    }
};

// Driver Code
int main() {
    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    int x = 2;
    Solution obj;
    cout << obj.minOperations(grid, x) << endl; // Output: 4
    return 0;
}
