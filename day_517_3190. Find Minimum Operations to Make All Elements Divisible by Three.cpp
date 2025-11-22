/*
3190. Find Minimum Operations to Make All Elements Divisible by Three

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.

 

Example 1:

Input: nums = [1,2,3,4]

Output: 3

Explanation:

All array elements can be made divisible by 3 using 3 operations:

Subtract 1 from 1.
Add 1 to 2.
Subtract 1 from 4.
Example 2:

Input: nums = [3,6,9]

Output: 0

 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50a
*/

// Intuition:
// - The problem asks to find the minimum number of operations required to make all elements divisible by 3.
// - An operation consists of changing a number to a number that is divisible by 3.
// - We can simply count how many numbers in the array are not divisible by 3, as each of those will require one operation.

// Approach:
// - Traverse the array and for each number, check if it's divisible by 3.
// - If a number is not divisible by 3, we count it because it will require one operation to make it divisible by 3.
// - The final answer will be the total count of such numbers that are not divisible by 3.


// Time Complexity:
// - The time complexity is O(n), where n is the number of elements in the input array `nums`, because we only need to iterate through the array once.

// Space Complexity:
// - The space complexity is O(1) since we are using a constant amount of extra space (just the variable `cnt`).

class Solution {
public:
    // Function to return the minimum operations required
    int minimumOperations(vector<int>& nums) {
        int cnt = 0; // Counter to track numbers not divisible by 3
        
        // Traverse each number in the array
        for(int &x : nums) {
            // If the number is not divisible by 3, we need an operation
            if(x % 3 != 0) {
                cnt++;
            }
        }

        // Return the count of numbers not divisible by 3
        return cnt;
    }
};
