/*
2560. House Robber IV
Solved
Medium
Topics
Companies
Hint
There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

 

Example 1:

Input: nums = [2,3,5,9], k = 2
Output: 5
Explanation: 
There are three ways to rob at least 2 houses:
- Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
- Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
- Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
Therefore, we return min(5, 9, 9) = 5.
Example 2:

Input: nums = [2,7,9,3,1], k = 2
Output: 2
Explanation: There are 7 ways to rob the houses. The way which leads to minimum capability is to rob the house at index 0 and 4. Return max(nums[0], nums[4]) = 2.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= (nums.length + 1)/2
*/

/**
 * Approach: Binary Search on Answer
 * - We binary search on the minimum "capability" needed to rob `k` houses.
 * - A helper function `isPossible()` checks if we can rob at most `k` houses for a given `mid`.
 *
 * 🔹 **Time Complexity:** O(N log(max−min)) → Binary search over possible values.
 * 🔹 **Space Complexity:** O(1) → Constant space used.
 */

class Solution {
public:
    // Helper function to check if it's possible to rob at least `k` houses with `mid` capability
    bool isPossible(vector<int> &nums, int mid, int k, int n){
        int house = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] <= mid){
                house++;  // Rob this house
                i++;      // Skip next house to avoid adjacent robbery
            }
        }

        return house >= k;  // Return true if we can rob at least `k` houses
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int res = r;  // Store the minimum valid capability

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(nums, mid, k, n)) {
                res = mid;  // Update result with valid capability
                r = mid - 1; // Try for a smaller capability
            }
            else {
                l = mid + 1; // Increase capability
            }
        }

        return res;
    }
};