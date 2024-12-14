/*
2762. Continuous Subarrays
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
Return the total number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [5,4,2,4]
Output: 8
Explanation: 
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
Thereare no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.
 

Example 2:

Input: nums = [1,2,3]
Output: 6
Explanation: 
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

/*
Approach:
1. Use the sliding window (two-pointer) technique to maintain a subarray of valid elements.
2. Use a `map` (or `unordered_map` if performance allows) to track the frequency of elements in the current window.
3. Expand the window by moving the `j` pointer and update the frequency map.
4. If the difference between the maximum and minimum values in the window exceeds 2, shrink the window by moving the `i` pointer until the condition is satisfied.
5. For each valid window, the number of valid subarrays is `(j - i + 1)`, which is added to the count.

Steps:
- Initialize `i` and `j` as pointers for the sliding window, and a `map` to track element frequencies.
- Traverse the array using the `j` pointer, expanding the window and adjusting the frequencies.
- If the difference between the maximum and minimum values exceeds `2`, adjust the `i` pointer to shrink the window.
- For each valid window, update the count of subarrays.

Time Complexity:
- O(n log n): The `map` operations (insert, erase, and find) take O(log n) time, and we process each element at most twice (once for `i` and once for `j`).

Space Complexity:
- O(n): Space for the `map` to store the frequency of elements in the current window.

Edge Cases:
- Single-element array.
- Array with elements that are all the same.
- All elements in the array are distinct.
*/

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int i = 0, j = 0;
        long long subArrCnt = 0;
        int n = nums.size();
        map<int, int> mp; // Map to store frequencies of elements in the current window

        // Traverse the array with the sliding window technique
        while (j < n) {
            // Add the current element to the window
            mp[nums[j]]++;

            // Get the maximum and minimum elements in the current window
            int maxVal = mp.rbegin()->first;
            int minVal = mp.begin()->first;

            // Shrink the window from the left if the difference between max and min exceeds 2
            while (i < j && maxVal - minVal > 2) {
                mp[nums[i]]--; // Decrease the frequency of the element at i
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]); // Remove the element if its frequency is 0
                }
                maxVal = mp.rbegin()->first; // Update max value
                minVal = mp.begin()->first; // Update min value
                i++; // Move the left pointer to shrink the window
            }

            // Add the number of valid subarrays in the current window
            subArrCnt += (j - i + 1);

            // Move the right pointer to expand the window
            j++;
        }

        return subArrCnt; // Return the total count of valid subarrays
    }
};