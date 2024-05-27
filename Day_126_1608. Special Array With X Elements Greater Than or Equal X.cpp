/*
1608. Special Array With X Elements Greater Than or Equal X
Solved
Easy
Topics
Companies
Hint
You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

 

Example 1:

Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
Example 2:

Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.
Example 3:

Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

// Intuition:
// - The problem requires us to find an integer `x` such that there are exactly `x` numbers in the array that are greater than or equal to `x`.
// - We can use binary search to efficiently find this integer `x` by sorting the array first and then checking each possible value of `x` from 0 to the size of the array.

// Time Complexity: O(N log N)
// - Sorting the array takes O(N log N).
// - For each value from 0 to N (where N is the size of the array), we perform a binary search using `lower_bound`, which takes O(log N). Thus, the overall complexity for this loop is O(N log N).

// Space Complexity: O(1)
// - We use a constant amount of extra space.

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array
        int n = nums.size();

        // Iterate through all possible values of `x` from 0 to n
        for(int i = 0; i <= n; i++) {
            // Find the index of the first element that is greater than or equal to `i` using `lower_bound`
            int idx = lower_bound(begin(nums), end(nums), i) - begin(nums);
            // Count of elements that are greater than or equal to `i`
            int cnt = n - idx;
            // Check if this count matches the current value of `i`
            if(i == cnt)
                return cnt;
        }
        // If no such value `x` is found, return -1
        return -1;
    }
};
