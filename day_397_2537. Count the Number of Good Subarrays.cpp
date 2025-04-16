/*
2537. Count the Number of Good Subarrays
Solved
Medium
Topics
Companies
Hint
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.
Example 2:

Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i], k <= 109
*/

/*
Intuition:
We want to count the number of subarrays that contain at least 'k' good pairs.
A pair is considered good if the two elements are equal and appear at different positions.

Approach:
We use the sliding window technique with two pointers `i` and `j`.
For each window [i..j], we maintain the number of good pairs using a hash map to store frequencies.
If the number of pairs in the window is >= k, then all subarrays starting from i and ending at j, j+1, ..., n-1 are valid.
So, we add (n - j) to our result, and shrink the window from the left until the number of pairs becomes < k.

Time Complexity: O(n)
- Each element is added and removed from the window at most once.

Space Complexity: O(n)
- For the hashmap used to store frequencies of elements in the current window.
*/

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int pairs = 0;
        long long res = 0;
        int i = 0, j = 0;

        while(j < n){
            // Increment pair count using current frequency of nums[j]
            pairs += mp[nums[j]];
            mp[nums[j]]++;

            // If we have enough good pairs, count all valid subarrays starting at i
            while(pairs >= k){
                res += (n - j); // All subarrays [i..j], [i..j+1], ..., [i..n-1] are valid
                mp[nums[i]]--;
                pairs -= mp[nums[i]]; // Update pair count when removing nums[i]
                i++;
            }

            j++;
        }

        return res;
    }
};
