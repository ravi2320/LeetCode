/*
1578. Minimum Time to Make Rope Colorful

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

 

Example 1:


Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
Example 2:


Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
Example 3:


Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the balloons at indices 0 and 4. Each balloons takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
 

Constraints:

n == colors.length == neededTime.length
1 <= n <= 105
1 <= neededTime[i] <= 104
colors contains only lowercase English letters.
*/

// Intuition:
// The problem asks us to minimize the cost of removing balloons so that no two adjacent balloons have the same color.
// To solve this, we will iterate through the string of balloon colors. When two adjacent balloons have the same color,
// we will remove the one with the lower cost, as we want to minimize the removal cost. This ensures that we keep the balloon
// with the higher removal cost and remove the one with the lower cost for each pair of adjacent balloons with the same color.
// The goal is to compute the total cost of removing the "cheaper" balloons for each pair of adjacent balloons with the same color.

// Time Complexity:
// O(n), where n is the length of the `colors` string. We only need one pass through the string to compute the result, 
// so the time complexity is linear in the size of the input.

// Space Complexity:
// O(1), because we are only using a few extra variables (prev, ans) that do not depend on the size of the input,
// so the space complexity is constant.

class Solution {
public:
    // Function to calculate the minimum cost of removing balloons with the same color
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();  // Length of the string `colors`
        int prev = 0, ans = 0;  // Initialize `prev` to 0 (the first balloon) and `ans` to 0 (total cost)

        // Iterate over the string starting from the second balloon (i = 1)
        for(int i = 1; i < n; i++) {
            // If the current balloon (i) has a different color from the previous balloon (prev), no need to remove anything
            if(colors[prev] != colors[i]) {
                prev = i;  // Update `prev` to the current balloon since the color is different
            } else {
                // If the colors are the same, we must remove one of them, so compare their removal costs
                if(neededTime[prev] < neededTime[i]) {
                    // If the previous balloon is cheaper to remove, add its cost to `ans` and update `prev` to the current balloon
                    ans += neededTime[prev];
                    prev = i;
                } else {
                    // If the current balloon is cheaper to remove, add its cost to `ans`
                    ans += neededTime[i];
                }
            }
        }

        // Return the total cost of removing the "cheaper" balloons
        return ans;
    }
};
