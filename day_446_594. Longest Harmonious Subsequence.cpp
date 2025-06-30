/*
594. Longest Harmonious Subsequence

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].

Example 2:

Input: nums = [1,2,3,4]

Output: 2

Explanation:

The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

Example 3:

Input: nums = [1,1,1,1]

Output: 0

Explanation:

No harmonic subsequence exists.

 

Constraints:

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109
*/

/*
Approach:
We need to find the length of the **longest harmonious subsequence** (LHS) where the difference between
the maximum and minimum elements is exactly 1.

Steps:
1. Sort the array to group similar numbers together and ensure increasing order.
2. Use a sliding window with two pointers (i and j).
   - Move the `i` pointer forward if the difference between nums[j] and nums[i] > 1.
   - If the difference is exactly 1, update the maximum length of the window [i, j].

Intuition:
- Sorting ensures that duplicates stay together and numbers are in increasing order.
- A window where `nums[j] - nums[i] == 1` contains all elements for a valid harmonious subsequence.
- We simply maximize the size of such a window.

Time Complexity:
- O(n log n): for sorting
- O(n): for sliding window

Space Complexity:
- O(1): only pointers and variables used
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        // Sort the array to apply sliding window
        sort(nums.begin(), nums.end());

        int i = 0, j = 1;
        int n = nums.size();
        int maxLen = 0;

        // Use two pointers to find valid harmonious subsequences
        while (j < n) {
            // Shrink window if the difference is greater than 1
            while (i < j && nums[j] - nums[i] > 1) {
                i++;
            }

            // If difference is exactly 1, update maxLen
            if (nums[j] - nums[i] == 1) {
                maxLen = max(maxLen, j - i + 1);
            }

            j++;
        }

        return maxLen;
    }
};

	/*
Approach:
We want to find the length of the longest harmonious subsequence (LHS),
where the maximum and minimum element differ by exactly 1.

Steps:
1. Count the frequency of each element using a hash map.
2. Iterate through each unique key in the map.
   - If the next consecutive key (key + 1) exists, we can form a valid subsequence.
   - The total length is the sum of frequencies of `key` and `key + 1`.
3. Track the maximum such length encountered.

Intuition:
- A harmonious subsequence must contain two consecutive numbers (like x and x+1).
- By using frequency counts, we efficiently determine how many elements can form such subsequences.

Time Complexity:
- O(n): We traverse the array once to build the frequency map and once more to find the max length.

Space Complexity:
- O(n): Space used by the frequency map.
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency of each element
        for (int &x : nums) {
            freq[x]++;
        }

        int maxLen = 0;

        // Check for each number if its consecutive exists
        for (auto &[key, val] : freq) {
            if (freq.count(key + 1)) {
                maxLen = max(maxLen, val + freq[key + 1]);
            }
        }

        return maxLen;
    }
};