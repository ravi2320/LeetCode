/*
2379. Minimum Recolors to Get K Consecutive Black Blocks
Solved
Easy
Topics
Companies
Hint
You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

 

Example 1:

Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW". 
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
Example 2:

Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.
 

Constraints:

n == blocks.length
1 <= n <= 100
blocks[i] is either 'W' or 'B'.
1 <= k <= n
*/

/**
 * Approach:
 * - Use a **sliding window of size K** to count the number of 'W' blocks.
 * - Slide the window across the string and keep track of the **minimum number of 'W's** encountered.
 *
 * 🔹 **Steps**:
 *   1️⃣ Maintain a count `cnt` of 'W' in the current **window of size K**.
 *   2️⃣ Slide the window across the string:
 *       - **Expand**: Add the rightmost element to `cnt`.
 *       - **Shrink**: Remove the leftmost element after the window size exceeds K.
 *   3️⃣ Keep track of the **minimum `cnt`** found.
 *   4️⃣ If at any point `cnt == 0`, return 0 (optimal case).
 *
 * 🔹 **Time Complexity**: O(N) → Single pass through the string.
 * 🔹 **Space Complexity**: O(1) → Uses only a few variables.
 */

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int ans = k, cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += (blocks[i] == 'W'); // Count 'W' in window

            if (i + 1 >= k) { // Window size reached
                ans = min(ans, cnt); // Update min recolors needed

                cnt -= (blocks[i - k + 1] == 'W'); // Remove leftmost element
                
                if (ans == 0) return 0; // If no recoloring needed, return immediately
            }
        }

        return ans;
    }
};
