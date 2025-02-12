/*
2342. Max Sum of a Pair With Equal Sum of Digits
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

/*
Approach:
1. **Digit Sum Calculation**:  
   - A helper function `digitSum(int num)` computes the sum of digits of a number.
2. **Hash Map (unordered_map) Usage**:
   - The key is the **digit sum** of a number.
   - The value stores the **largest number** seen with that digit sum.
3. **Iterate through the array**:
   - If a number with the same digit sum exists, update the maximum sum (`maxi`).
   - Update the hash map with the **maximum** value for that digit sum.

Intuition:
- Two numbers have the **same digit sum** if their individual digits add up to the same total.
- The problem asks for the **maximum sum of two numbers with the same digit sum**, so we:
  1. **Group numbers** by their digit sum.
  2. **Keep track of the largest** number seen for each digit sum.
  3. **Compare and update** the maximum pair sum found.

Time Complexity: **O(N log M)**
- **O(log M)** for digit sum computation (`M` is the max number value).
- **O(N)** for iterating over `nums`.
- **O(N log M)** overall.

Space Complexity: **O(N)**
- Hash map stores at most `N` unique digit sums.
*/

class Solution {
public:
    // Helper function to compute sum of digits
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    } 

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; // Stores max num for each digit sum
        int maxi = -1; // Default return value if no valid pair exists

        for (int i = 0; i < n; i++) {
            int sum = digitSum(nums[i]);

            // Check if we have another number with the same digit sum
            if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, nums[i] + mp[sum]); // Update max pair sum
                mp[sum] = max(mp[sum], nums[i]); // Keep the larger number
            } else {
                mp[sum] = nums[i]; // Store the first number for this digit sum
            }
        }

        return maxi;
    }
};