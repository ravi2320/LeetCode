/*
3228. Maximum Number of Operations to Move Ones to the End

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a binary string s.

You can perform the following operation on the string any number of times:

Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
Return the maximum number of operations that you can perform.

 

Example 1:

Input: s = "1001101"

Output: 4

Explanation:

We can perform the following operations:

Choose index i = 0. The resulting string is s = "0011101".
Choose index i = 4. The resulting string is s = "0011011".
Choose index i = 3. The resulting string is s = "0010111".
Choose index i = 2. The resulting string is s = "0001111".
Example 2:

Input: s = "00111"

Output: 0

 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
*/

/*
Intuition:
- We are given a string of '0's and '1's. The goal is to count the number of "valid operations" we can perform.
- A valid operation consists of finding a subsequence of '1's and '0's such that there is a '1' before each '0'. We are to count how many times this can happen as we traverse the string.

Approach:
- We will traverse the string from left to right. We maintain:
  1. A counter `ones` to count the number of '1's encountered so far.
  2. An answer variable `ans` to accumulate the number of valid operations.
  3. As we encounter a '0', we add the number of '1's seen so far to `ans` (since each '1' before the '0' can form a valid operation).
- Each time we encounter a '1', we increase the `ones` counter.
- We continue until the end of the string.

Time Complexity:
- The solution involves a single pass through the string, so the time complexity is O(n), where n is the length of the string.

Space Complexity:
- We are using only a constant amount of extra space, so the space complexity is O(1).
*/

class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();  // Get the length of the string

        int i = 0, ans = 0, ones = 0;  // Initialize index, answer counter, and counter for '1's

        // Traverse through the string
        while(i < n){
            // If we encounter a '0', process it
            if(s[i] == '0'){
                // Count the number of valid operations for this '0'
                while(i < n && s[i] == '0')  // Skip all consecutive '0's
                    i++;  // Move to the next character
                ans += ones;  // Add the number of '1's before this '0' to the answer
            }

            // If we encounter a '1', increment the counter for '1's
            if(s[i] == '1')
                ones++;

            i++;  // Move to the next character
        }

        return ans;  // Return the total number of valid operations
    }
};
