/*
2799. Count Complete Subarrays in an Array
Solved
Medium
Topics
Companies
Hint
You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

 

Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2000
*/

/*
Intuition:
A "complete" subarray is one that contains all the distinct elements present in the entire array.
So, we first find how many distinct elements are in the array, and then we use a sliding window
to count all subarrays that include all these distinct elements.

Approach:
1. Count the total number of distinct elements in the array using a set.
2. Use a sliding window [i...j] to check how many subarrays from index i to j (and beyond) contain all distinct elements.
3. Whenever the number of distinct elements in the current window equals the total, we add (n - j)
   to the result because all subarrays starting at i and ending at j to n-1 are valid.

Time Complexity: O(N)
- We visit each element at most twice (once for j++, once for i++) in the sliding window approach.

Space Complexity: O(N)
- For storing frequency counts and the initial distinct elements set.
*/

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        // Step 1: Count total distinct elements in nums
        unordered_set<int> st(nums.begin(), nums.end());
        int distinctElement = st.size();

        unordered_map<int, int> mp;
        int i = 0, j = 0;

        // Step 2: Sliding window
        while (j < n) {
            mp[nums[j]]++;

            // When the window has all distinct elements
            while (mp.size() == distinctElement) {
                res += (n - j); // All subarrays starting at i and ending from j to n-1 are valid
                mp[nums[i]]--;

                // Clean up the map if count drops to zero
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            j++;
        }

        return res;
    }
};