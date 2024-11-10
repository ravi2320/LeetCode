/*
3097. Shortest Subarray With OR at Least K II
Solved
Medium
Topics
Companies
Hint
You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty 
subarray
 of nums, or return -1 if no special subarray exists.

 

Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.

 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 109
0 <= k <= 109
*/

/*
Approach:
1. Use a sliding window approach to find the smallest subarray with a bitwise OR that is at least `k`.
2. Maintain an array `vec` to keep track of the bit count for each bit position (0 to 31).
   - The `update` function increments or decrements the bit count in `vec` for each bit set in `num`.
   - The `getBinaryToDecimal` function calculates the bitwise OR of the current window from `vec` by setting bits where the count is greater than zero.
3. Expand the window by moving `j` and including `nums[j]` in `vec`.
4. If the OR result of the current window is greater than or equal to `k`, shrink the window by moving `i` to minimize the subarray length while still satisfying the condition.
5. Update the result with the minimum subarray length found that meets the condition.

Time Complexity: O(32 * n), where `n` is the number of elements in `nums`, since each window shift requires O(32) operations.
Space Complexity: O(32), for the `vec` array.

*/

class Solution {
public:
    // Function to update the bit count array `vec` based on `num`
    void update(int num, vector<int> &vec, int val){
        for(int i = 0; i < 32; i++) {
            if(num & (1 << i)) {
                vec[i] += val;
            }
        }
    }

    // Function to calculate the OR result from the bit count array `vec`
    int getBinaryToDecimal(vector<int> &vec){
        int num = 0;
        for(int i = 0; i < 32; i++) {
            if(vec[i]) {
                num |= (1 << i);
            }
        }
        return num;
    }

    // Function to find the minimum subarray length with OR result >= k
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec(32, 0); // bit count for each bit position
        int i = 0, j = 0;
        int res = INT_MAX;

        // Sliding window approach
        while(j < n){
            update(nums[j], vec, 1); // add nums[j] to the window

            // Shrink the window from the left while OR result >= k
            while(i <= j && getBinaryToDecimal(vec) >= k) {
                res = min(res, j - i + 1); // update the result with minimum length
                update(nums[i], vec, -1); // remove nums[i] from the window
                i++;
            }
            j++;
        }

        return res == INT_MAX ? -1 : res; // return -1 if no subarray meets the condition
    }
};
