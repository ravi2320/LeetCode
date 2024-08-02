/*
2134. Minimum Swaps to Group All 1's Together II
Solved
Medium
Topics
Companies
Hint
A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

 

Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
Example 2:

Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
Example 3:

Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

/*
Intuition:
The goal is to find the minimum number of swaps required to group all 1s in a circular array together. By duplicating the array, we can treat it as a linear problem. We use a sliding window approach to find the maximum number of 1s in a window of size equal to the total number of 1s in the original array.

Time Complexity:
The time complexity is O(n) where n is the size of the input array. This is because each element in the extended array is processed once.

Space Complexity:
The space complexity is O(n) for the extended array `temp`.

*/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Extend the array by concatenating it with itself
        vector<int> temp(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            temp[i] = nums[i % n];
        }

        // Calculate the total number of 1s in the original array
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        // Variables to keep track of the current number of 1s in the window
        int currOnes = 0;
        int left = 0;
        int right = 0;
        int maxOnes = INT_MIN;

        // Sliding window to find the maximum number of 1s in any window of size totalOnes
        while (right < 2 * n) {
            if (temp[right]) {
                currOnes++;
            }

            // If the window size exceeds totalOnes, shrink the window from the left
            while (right - left + 1 > totalOnes) {
                if (temp[left]) {
                    currOnes--;
                }
                left++;
            }

            // Update the maximum number of 1s found in any window of size totalOnes
            maxOnes = max(maxOnes, currOnes);
            right++;
        }

        // The minimum swaps required is the difference between totalOnes and maxOnes
        return totalOnes - maxOnes;
    }
};
