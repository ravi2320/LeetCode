/*
930. Binary Subarrays With Sum
Solved
Medium
Topics
Companies
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

/*
Approach:
1. The task is to find the number of subarrays with a sum equal to a given `goal`.
2. Two methods are used:
   - **Prefix Sum and HashMap** (commented out): Keep track of cumulative sums and their frequencies, using the difference between the current sum and the `goal` to count valid subarrays.
   - **Sliding Window (optimized approach)**: Count subarrays whose sum is exactly `goal` using a helper function `slidingWindow`. 

   The sliding window approach uses the fact that:
   - `slidingWindow(nums, goal)` gives the count of subarrays with a sum <= `goal`.
   - To find the count of subarrays with an exact sum of `goal`, subtract the count of subarrays with sum <= `goal-1` from that of `goal`.

Steps:
1. Define the helper function `slidingWindow` to count subarrays with sum ≤ `goal` using two pointers.
2. Use the helper function to calculate the result as the difference between subarray counts for `goal` and `goal-1`.

Time Complexity:
- O(n): Both the sliding window and prefix sum approaches run in linear time.

Space Complexity:
- O(1): Sliding window uses constant space.
- O(n): Prefix sum approach requires space for the hash map.

Edge Cases:
- Empty input array.
- `goal` is 0.
- Array contains only 0s or only 1s.

*/

class Solution {
public:
    // Helper function to count subarrays with sum <= goal using sliding window
    int slidingWindow(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // No subarray can have a negative sum

        int i = 0, j = 0, n = nums.size(), ans = 0;
        int sum = 0;

        // Sliding window to count subarrays with sum <= goal
        while (j < n) {
            sum += nums[j]; // Add the current element to the window

            // Shrink the window if the sum exceeds the goal
            while (sum > goal) {
                sum -= nums[i++]; // Remove the leftmost element
            }

            ans += (j - i + 1); // Add the count of valid subarrays ending at `j`
            j++; // Expand the window
        }

        return ans;
    }

    // Function to count subarrays with sum exactly equal to `goal`
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Optimized approach using sliding window
        return slidingWindow(nums, goal) - slidingWindow(nums, goal - 1);

        // Uncomment for prefix sum approach:
        /*
        unordered_map<int, int> preSum;
        int sum = 0, ans = 0;
        preSum[0] = 1; // Base case: one way to get sum 0 (empty subarray)

        for (int &x : nums) {
            sum += x; // Update cumulative sum
            int reqSum = sum - goal; // Calculate the required sum

            ans += preSum[reqSum]; // Add the count of subarrays with the required sum
            preSum[sum]++; // Update the frequency of the current sum
        }

        return ans;
        */
    }
};
