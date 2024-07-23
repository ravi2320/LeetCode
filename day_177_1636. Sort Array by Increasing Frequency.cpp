/*
1636. Sort Array by Increasing Frequency
Solved
Easy
Topics
Companies
Hint
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

/**
 * Intuition:
 * 1. **Frequency Count:** Use a hashmap to count the frequency of each number.
 * 2. **Sorting:** Sort the array based on the frequency of elements. If frequencies are equal, sort by the value in descending order.
 *
 * Time Complexity: O(n log n)
 * - O(n) for frequency counting.
 * - O(n log n) for sorting the array.
 *
 * Space Complexity: O(n)
 * - Space for the hashmap to store frequency counts.
 */

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        // Count frequency of each number
        for(int &x : nums){
            mp[x]++;
        }

        // Sort the numbers based on frequency and value
        sort(nums.begin(), nums.end(), 
        [&](int &a, int &b){
            // If frequencies are different, sort by frequency in ascending order
            // If frequencies are the same, sort by value in descending order
            return mp[a] != mp[b] ? mp[a] < mp[b] : a > b;
        });

        return nums;
    }
};
