/*
1283. Find the Smallest Divisor Given a Threshold
Solved
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106
*/

/*
 * Intuition:
 * The goal is to find the smallest divisor such that the sum of the ceiling values of the division of each element by the divisor is less than or equal to a given threshold.
 * This can be efficiently achieved using binary search. The search space for the divisor is between 1 and the maximum element in the array.
 * For each candidate divisor, calculate the sum of the ceiling values and adjust the search range accordingly.
 *
 * Time Complexity: O(n log m), where n is the number of elements in the array and m is the maximum element in the array. Binary search runs in O(log m) and for each candidate divisor, we compute the sum in O(n).
 * Space Complexity: O(1), as we only use a few extra variables for our calculations.
 */

class Solution {
public:
    // Helper function to calculate the sum of the ceiling values of the division of each element by the divisor
    int findSum(vector<int>& nums, int divisor) {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += (nums[i] + divisor - 1) / divisor;  // Equivalent to ceil((double)nums[i] / (double)divisor)
        }

        return sum;
    }

    // Main function to find the smallest divisor
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        if (n == threshold)
            return high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = findSum(nums, mid);

            if (sum <= threshold) {
                high = mid - 1;  // Try to find a smaller divisor
            } else {
                low = mid + 1;   // Increase the divisor
            }
        }

        return low;
    }
};
