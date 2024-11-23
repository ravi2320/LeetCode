/*
1861. Rotating the Box
Solved
Medium
Topics
Companies
Hint
You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

 

Example 1:



Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
Example 2:



Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
Example 3:



Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
 

Constraints:

m == box.length
n == box[i].length
1 <= m, n <= 500
box[i][j] is either '#', '*', or '.'.
*/

/*
Approach:
1. The problem requires rotating a 2D grid (representing a box) and adjusting the positioning of stones ('#') based on gravity, where stones should fall to the bottom unless blocked by obstacles ('*').
2. The solution involves two main steps:
   - **Rotation** of the matrix by 90 degrees clockwise.
   - **Gravity Adjustment** where stones fall to the nearest available position from bottom to top.
   
Steps:
1. Rotate the matrix by transposing the rows into columns and then reversing each row.
2. Adjust the stones based on gravity after the rotation:
   - Iterate each column from the bottom to the top.
   - Track the nearest empty position where a stone can fall.
   - Move the stone to the empty spot if possible and update the empty position.

Time Complexity:
- O(n * m) — where `n` is the number of rows and `m` is the number of columns.
  We iterate through each cell multiple times during the rotation and gravity adjustment.

Space Complexity:
- O(n * m) — for storing the rotated matrix.

*/

class Solution {
public:
    // Function to rotate the box and adjust stones due to gravity
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();  // Dimensions of the input box
        vector<vector<char>> res(m, vector<char>(n));  // Resulting rotated box

        // Step 1: Rotate the box by transposing it and then reversing rows
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j][i] = box[i][j];  // Transpose operation
            }
        }

        // Reverse each row of the transposed matrix to achieve a 90-degree rotation
        for (auto &row : res) {
            reverse(row.begin(), row.end());
        }

        // Step 2: Adjust stones ('#') to fall to the bottom of the grid
        for (int j = 0; j < n; j++) {
            int currEmptySpot = m - 1;  // Start from the bottom of each column

            // Iterate from the bottom to the top of the current column
            for (int i = m - 1; i >= 0; i--) {
                if (res[i][j] == '*') {
                    // If an obstacle is found, update the empty spot
                    currEmptySpot = i - 1;
                    continue;
                }

                if (res[i][j] == '#') {
                    // Move stone to the nearest empty spot
                    res[i][j] = '.';
                    res[currEmptySpot][j] = '#';
                    currEmptySpot--;
                }
            }
        }

        return res;  // Return the rotated and adjusted box
    }
};
