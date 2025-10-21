/*
3346. Maximum Frequency of an Element After Performing Operations I
Solved

avatar
Discuss Approach
arrow-up
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing the operations.

 

Example 1:

Input: nums = [1,4,5], k = 1, numOperations = 2

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1]. nums becomes [1, 4, 5].
Adding -1 to nums[2]. nums becomes [1, 4, 4].
Example 2:

Input: nums = [5,11,20,20], k = 5, numOperations = 1

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
0 <= k <= 105
0 <= numOperations <= nums.length
*/

/*
 * Intuition:
 * The goal is to find the maximum frequency of any element in the array after performing at most 'numOperations' operations, 
 * where an operation is the addition or subtraction of any number by at most 'k'. 
 * To achieve this, we consider all possible target values that could result from the operations.
 * We then calculate how many elements can be transformed into that target value with at most 'numOperations' operations.
 * The result will be the maximum possible frequency we can achieve by changing the elements to a specific target value.

 * Time Complexity:
 * O(n + m * log(m)) where:
 *   n = the size of the input array `nums`, and 
 *   m = the largest element in `nums` + k.
 * The time complexity is dominated by the operations of iterating through the array and the range of possible target values.

 * Space Complexity:
 * O(m), where m = the largest element in `nums` + k. This space is used by the `freq` array to store the frequency counts.
 */

class Solution {
public:
    // Function to find the maximum frequency after performing at most `numOperations` operations
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // Step 1: Find the largest element in nums, and we need to consider values up to maxElement + k.
        int maxEle = *max_element(nums.begin(), nums.end()) + k;

        // Step 2: Create a frequency array to count occurrences of each element.
        vector<int> freq(maxEle + 1, 0);

        // Step 3: Populate the frequency array with counts from the `nums` array.
        for (int &x : nums) {
            freq[x]++;
        }

        // Step 4: Convert the `freq` array into a prefix sum array so that freq[i] gives 
        // the total number of elements less than or equal to `i`.
        for (int i = 1; i <= maxEle; i++) {
            freq[i] += freq[i - 1];
        }

        // Step 5: Initialize the answer variable that will store the maximum frequency.
        int ans = 0;

        // Step 6: Iterate through all possible target values (from 0 to maxEle).
        for (int target = 0; target <= maxEle; target++) {
            // Determine the range of values [leftNum, rightNum] that can potentially be transformed into the `target` value
            int leftNum = max(target - k, 0);   // left boundary of the range
            int rightNum = min(target + k, maxEle);  // right boundary of the range

            // Calculate the total number of elements in the range [leftNum, rightNum]
            int totalCount = freq[rightNum] - (leftNum > 0 ? freq[leftNum - 1] : 0);

            // Calculate the number of elements already equal to `target`
            int targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);

            // Calculate how many additional elements need to be converted to the target
            int needConversion = totalCount - targetCount;

            // Determine how many elements can be converted to the target, considering the number of operations available
            int maxPossible = targetCount + min(needConversion, numOperations); 

            // Update the answer with the maximum possible frequency
            ans = max(ans, maxPossible);
        }

        // Step 7: Return the maximum frequency found.
        return ans;
    }
};
