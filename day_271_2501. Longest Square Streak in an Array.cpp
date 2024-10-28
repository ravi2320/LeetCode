/*
2501. Longest Square Streak in an Array
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums. A subsequence of nums is called a square streak if:

The length of the subsequence is at least 2, and
after sorting the subsequence, each element (except the first element) is the square of the previous number.
Return the length of the longest square streak in nums, or return -1 if there is no square streak.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [4,3,6,16,8,2]
Output: 3
Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
- 4 = 2 * 2.
- 16 = 4 * 4.
Therefore, [4,16,2] is a square streak.
It can be shown that every subsequence of length 4 is not a square streak.
Example 2:

Input: nums = [2,3,5,6,7]
Output: -1
Explanation: There is no square streak in nums so return -1.
 

Constraints:

2 <= nums.length <= 105
2 <= nums[i] <= 105
*/

/*
Approach:
1. Sort the array `nums` to ensure we process smaller elements first.
2. Initialize an unordered map `mp` to store the longest square streak ending at each number.
3. For each element `x` in `nums`:
   - Check if `x` is a perfect square of an integer `root` (i.e., root * root == x).
   - If true, check if `mp` contains `root`. If `root` exists in `mp`, it means `root` is part of a previous streak.
     - Set `mp[x]` as `mp[root] + 1` to extend the streak from `root` to `x`.
   - If `x` is not a square or there is no `root` entry in `mp`, start a new streak by setting `mp[x] = 1`.
4. Track the longest streak in `maxStreak` by updating it with `mp[x]` at each step.
5. Return `maxStreak` if it is greater than 1; otherwise, return -1 to indicate no valid streak.

Time Complexity: O(n log n) for sorting the array + O(n) for processing each element, where `n` is the number of elements in `nums`.
Space Complexity: O(n) for storing the streak lengths in `mp`.

*/

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> mp;  // Store the length of square streaks ending at each number

        sort(nums.begin(), nums.end());  // Sort to process numbers in ascending order
        int maxStreak = 0;  // Variable to track the maximum streak length

        // Traverse each element in the sorted list
        for (int &x : nums) {
            int root = (int)sqrt(x);  // Calculate the integer square root of x

            // Check if x is a perfect square and root is part of a previous streak
            if (root * root == x && mp.find(root) != mp.end()) {
                mp[x] = mp[root] + 1;  // Extend the streak from root to x
            } else {
                mp[x] = 1;  // Start a new streak with x
            }

            maxStreak = max(maxStreak, mp[x]);  // Update the maximum streak length
        }

        return maxStreak == 1 ? -1 : maxStreak;  // Return -1 if no streak > 1 exists
    }
};


/*
Approach:
1. Use an unordered set `st` to store all elements in `nums` for quick lookup.
2. For each element `x` in `nums`, attempt to form a square streak:
   - Initialize `streak` to track the current streak length starting from `x`.
   - Continuously square `x` and check if the squared value exists in `st`.
     - If it does, increment the `streak` length and update `x` to `x * x`.
     - If `x * x` exceeds the upper bound of elements in `nums` (assumed here as `1e5`), break to avoid overflow.
3. Track the maximum streak length in `maxStreak`.
4. If the maximum streak found is only 1, return -1, as no valid square streaks exist; otherwise, return `maxStreak`.

Time Complexity: O(n log k), where `n` is the number of elements and `k` is the number of squaring operations within bounds.
Space Complexity: O(n) for storing elements in the unordered set.

*/

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());  // Store elements for fast lookup

        int maxStreak = 1;  // Track the maximum streak length
        for (long long x : nums) {
            int streak = 0;  // Initialize streak length for each element

            // Square elements in sequence as long as they exist in the set
            while (st.count(x)) {
                streak++;  // Increment streak length
                if (x * x > 1e5) break;  // Break if next square exceeds bound
                x *= x;  // Move to the next square
            }

            maxStreak = max(maxStreak, streak);  // Update max streak length
        }   

        return maxStreak == 1 ? -1 : maxStreak;  // Return -1 if no streak > 1 exists
    }
};
