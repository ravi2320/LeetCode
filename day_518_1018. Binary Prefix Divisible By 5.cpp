/*
1018. Binary Prefix Divisible By 5

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given a binary array nums (0-indexed).

We define xi as the number whose binary representation is the subarray nums[0..i] (from most-significant-bit to least-significant-bit).

For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.
Return an array of booleans answer where answer[i] is true if xi is divisible by 5.

 

Example 1:

Input: nums = [0,1,1]
Output: [true,false,false]
Explanation: The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.
Only the first number is divisible by 5, so answer[0] is true.
Example 2:

Input: nums = [1,1,1]
Output: [false,false,false]
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

// Intuition:
// We are given a binary array `nums`, where each number is either 0 or 1.
// We need to check for each prefix of the array (from 0 to i-th index), if the number formed by that prefix is divisible by 5.
// Instead of constructing the full number (which could be very large), we only maintain the remainder of the number modulo 5, 
// because if a number is divisible by 5, its remainder when divided by 5 will be 0. This keeps our calculations efficient.

// Approach:
// - Start with an initial number `num` = 0 (representing an empty prefix).
// - Traverse the array, at each index, update `num` by shifting it left (multiply by 2) and adding the current bit (`nums[i]`).
// - After updating `num`, reduce it modulo 5. This way, we maintain only the remainder of the number modulo 5 at each step.
// - If at any index `i`, `num % 5 == 0`, it means the number formed by the prefix `nums[0]` to `nums[i]` is divisible by 5, so we set `ans[i] = true`.

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();    // Get the size of the input array
        vector<bool> ans(n, false);  // Result vector to store answers for each prefix
        
        int num = 0;  // Variable to store the number formed by the binary prefix

        // Traverse through the input array
        for (int i = 0; i < n; i++) {
            // Update num: shift left (multiply by 2) and add current digit (nums[i])
            // Use modulo 5 to keep num in range [0, 4]
            num = (num * 2 + nums[i]) % 5;

            // If the current number formed by prefix is divisible by 5, set ans[i] to true
            if (num == 0)
                ans[i] = true;
        }

        return ans;  // Return the result vector
    }
};

// Time Complexity: O(n), where n is the number of elements in the input array `nums`.
//     - We iterate through the array once, and in each iteration, we perform constant time operations (multiplication, addition, modulo).

// Space Complexity: O(n), where n is the number of elements in the input array `nums`.
//     - We store the results in the `ans` vector, which has the same size as the input array `nums`.
