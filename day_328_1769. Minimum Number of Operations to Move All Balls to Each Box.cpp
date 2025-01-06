/*
1769. Minimum Number of Operations to Move All Balls to Each Box
Solved
Medium
Topics
Companies
Hint
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

 

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]
 

Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.
*/

/*
Approach:
1. Iterate through the `boxes` string.
2. For each box containing a ball ('1'), calculate the distance to every other box and add the result to their respective positions in the result array `ans`.
3. Use the `abs(j - i)` function to compute the absolute distance between box indices.

Intuition:
This brute-force approach considers all possible pairs of boxes and calculates the contribution of each ball to every other box. It ensures accurate results but is less efficient due to its nested loop structure.

Time Complexity:
- Outer loop: \(O(N)\), where \(N\) is the size of the string.
- Inner loop: \(O(N)\) for each iteration of the outer loop.
Overall: \(O(N^2)\).

Space Complexity:
- The result array `ans` requires \(O(N)\) space.
- No additional significant space is used.
Overall: \(O(N)\).

*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();              // Length of the string
        vector<int> ans(n, 0);             // Result array to store operations for each box

        // Iterate through each box
        for (int i = 0; i < n; i++) {
            // Check if the current box contains a ball
            if (boxes[i] == '1') {
                // Update the operation count for every other box
                for (int j = 0; j < n; j++) {
                    ans[j] += abs(j - i);  // Add the distance between box `i` and box `j`
                }
            }
        }

        return ans; // Return the result array
    }
};


/*
Approach:
1. Use two passes to calculate the number of operations for each box.
   - First pass (left-to-right): Calculate the operations required to move balls from all boxes on the left to the current box.
   - Second pass (right-to-left): Add the operations required to move balls from all boxes on the right to the current box.
2. Use cumulative values to track the number of balls (`cummVal`) and their total contribution (`cummValSum`) during each pass.

Intuition:
By iterating through the string twice, we efficiently calculate the number of operations for each box without recalculating contributions repeatedly, making the solution linear in time complexity.

Time Complexity:
- First pass: \(O(N)\), where \(N\) is the size of the string.
- Second pass: \(O(N)\).
Overall: \(O(N)\).

Space Complexity:
- The result array `ans` requires \(O(N)\) space.
- Other variables use \(O(1)\) space.
Overall: \(O(N)\).

*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();              // Length of the string
        vector<int> ans(n, 0);             // Result array to store operations for each box

        int cummVal = 0;                   // Cumulative count of balls encountered
        int cummValSum = 0;                // Cumulative sum of operations for balls from the left

        // First pass: Left-to-right
        for (int i = 0; i < n; i++) {
            ans[i] = cummValSum;           // Assign the current cumulative sum to the result
            cummVal += (boxes[i] == '0' ? 0 : 1); // Update the count of balls
            cummValSum += cummVal;         // Add the cumulative value to the total sum
        }

        // Reset cumulative values for the second pass
        cummVal = 0;
        cummValSum = 0;

        // Second pass: Right-to-left
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += cummValSum;          // Add the cumulative sum from the right to the result
            cummVal += (boxes[i] == '0' ? 0 : 1); // Update the count of balls
            cummValSum += cummVal;         // Add the cumulative value to the total sum
        }

        return ans; // Return the result array
    }
};