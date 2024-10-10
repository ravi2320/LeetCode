/*
962. Maximum Width Ramp
Solved
Medium
Topics
Companies
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

 

Example 1:

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
Example 2:

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
 

Constraints:

2 <= nums.length <= 5 * 104
0 <= nums[i] <= 5 * 104
*/

/*
Approach:
1. We need to find the maximum width ramp, where a ramp is defined as i < j and nums[i] <= nums[j].
2. We use a `rightMax` array, where `rightMax[i]` stores the maximum value from `nums[i]` to `nums[n-1]`. This helps efficiently find the largest `j` such that `nums[i] <= nums[j]`.
3. The algorithm uses two pointers:
   - `i` to scan through the array for potential start points of the ramp.
   - `j` to scan through the `rightMax` array for potential endpoints.

4. **Time Complexity**:
   - Building the `rightMax` array takes **O(n)**.
   - The two-pointer traversal takes **O(n)**.
   - Overall time complexity: **O(n)**.

5. **Space Complexity**:
   - The extra space used is for the `rightMax` array, which is **O(n)**.
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ramp = 0; // Stores the maximum width of the ramp found
        int n = nums.size(); // Size of the input array

        // Step 1: Create an array to store the maximum values from right to left
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        
        // Fill the rightMax array: rightMax[i] contains the max value from nums[i] to nums[n-1]
        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        // Step 2: Use two pointers to find the maximum width ramp
        int i = 0, j = 0; // Initialize two pointers
        
        while(j < n) {
            // Move i to the right while nums[i] is greater than rightMax[j]
            while(i < j && nums[i] > rightMax[j]) {
                i++;
            }

            // Calculate the ramp width and update the maximum if needed
            ramp = max(ramp, j - i);
            
            // Move j to the right
            j++;
        }

        // Return the maximum width ramp found
        return ramp;
    }
};
