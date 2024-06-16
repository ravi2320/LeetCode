/*
330. Patching Array
Solved
Hard
Topics
Companies
Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

Return the minimum number of patches required.

 

Example 1:

Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.
Example 2:

Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].
Example 3:

Input: nums = [1,2,2], n = 5
Output: 0
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
nums is sorted in ascending order.
1 <= n <= 231 - 1
*/

/*
Intuition:
- The problem is to find the minimum number of patches (new elements) needed to add to the array `nums` so that we can represent every number from 1 to `n` using the elements of the modified array.
- We use a greedy approach to keep track of the maximum number we can form with the current elements and patches.
- If the next number in `nums` is within the current maximum reach + 1, we extend our reach using this number.
- If it is not, we add a patch to extend our reach by the current maximum reach + 1.

Approach:
1. Initialize `patch` (number of patches) to 0, `i` (index for `nums`) to 0, and `maxReach` (current maximum reachable number) to 0.
2. Iterate until `maxReach` is less than `n`:
   - If `i` is within the bounds of `nums` and `nums[i]` is less than or equal to `maxReach + 1`, add `nums[i]` to `maxReach` and increment `i`.
   - Otherwise, add `maxReach + 1` as a patch, increment the patch count, and update `maxReach`.
3. Return the number of patches needed.

Time Complexity:
- O(m + log n), where `m` is the size of `nums`. In the worst case, the number of patches added is logarithmic in `n`.

Space Complexity:
- O(1), as the solution uses constant extra space.

*/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0;  // Number of patches needed
        int i = 0;      // Index for iterating through nums
        long maxReach = 0; // Current maximum reachable number

        while(maxReach < n) {
            if(i < nums.size() && nums[i] <= maxReach + 1) {
                // Extend the reach using the current number in nums
                maxReach += nums[i];
                i++;
            } else {
                // Add a patch to extend the reach
                maxReach += maxReach + 1;
                patch++;
            }
        }

        return patch;
    }
};
