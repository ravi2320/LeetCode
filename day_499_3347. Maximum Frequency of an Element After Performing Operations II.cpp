/*
3347. Maximum Frequency of an Element After Performing Operations II

avatar
Discuss Approach
arrow-up
Solved
Hard
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

Adding 0 to nums[1], after which nums becomes [1, 4, 5].
Adding -1 to nums[2], after which nums becomes [1, 4, 4].
Example 2:

Input: nums = [5,11,20,20], k = 5, numOperations = 1

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 109
0 <= numOperations <= nums.length
*/

// Intuition:
// We aim to find the maximum frequency of any number that can be achieved after at most `numOperations` operations,
// where each operation can increase an element by at most `k`.
//
// Approach:
// 1. We first calculate the frequency of each element and store it in a frequency map (`freq`).
// 2. Then, for each element, we compute the possible range of numbers it can transform into using `k` operations.
//    We track the number of possible transformations using a difference map (`diff`).
// 3. Finally, we compute the maximum frequency by evaluating how many numbers can be transformed into each target, 
//    considering the available number of operations (numOperations).

// Time Complexity:
// - Building the frequency map: O(n)
// - Constructing the difference map: O(n)
// - Iterating through the difference map: O(n)
// Overall Time Complexity: O(n)

// Space Complexity:
// - The frequency map (`freq`) stores counts for each distinct element, O(n) space.
// - The difference map (`diff`) has at most O(n) distinct values (if all numbers are unique).
// Overall Space Complexity: O(n)

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // Step 1: Find the maximum value in the array to define the range for the difference map.
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // Frequency map: stores the frequency of each number in the array.
        unordered_map<int, int> freq;
        
        // Difference map: helps in tracking the ranges of numbers that can be transformed to each target.
        map<int, int> diff;

        // Step 2: Populate the frequency map and the difference map based on the possible ranges.
        for(int &num : nums) {
            // Update the frequency map with the current number
            freq[num]++;

            // Calculate the range [l, r] for the current number considering the allowed operations
            int l = max(num - k, 0);  // lower bound for transformation
            int r = min(num + k, maxVal);  // upper bound for transformation

            // Update the difference map to reflect the range where transformations are possible
            diff[l]++;      // Start of the range where transformations can begin
            diff[r + 1]--;  // End of the range, exclusive

            // The current number itself does not need any transformations (no effect)
            diff[num] += 0;
        }

        // Step 3: Iterate over the difference map to calculate the maximum frequency.
        int res = 0;      // The result stores the maximum frequency encountered
        int cummSum = 0;  // Cumulative sum to track the total effect of transformations

        for(auto it = diff.begin(); it != diff.end(); it++) {
            int target = it->first;    // The current target number
            it->second += cummSum;     // Update the current transformation count by adding the cumulative sum

            // Get the frequency of the current target number
            int targetFreq = freq[target];
            
            // Calculate how many numbers can be transformed into the target number
            int needConversion = it->second - targetFreq;
            
            // Limit the possible conversions to the available number of operations
            int maxPossible = min(needConversion, numOperations);
            
            // Calculate the maximum possible frequency for the current target
            res = max(res, targetFreq + maxPossible);
            
            // Update the cumulative sum for the next iteration
            cummSum = it->second;
        }

        // Return the result, which is the maximum frequency
        return res;
    }
};
