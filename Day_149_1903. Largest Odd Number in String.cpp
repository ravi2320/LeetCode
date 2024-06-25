/*
1903. Largest Odd Number in String
Solved
Easy
Topics
Companies
Hint
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
 

Constraints:

1 <= num.length <= 105
num only consists of digits and does not contain any leading zeros.
*/

/**
 * Intuition:
 * - To find the largest odd number in a string, we need to identify the rightmost odd digit in the string.
 * - If an odd digit is found, the largest odd number is the substring from the start of the string to this odd digit.
 * - If no odd digit is found, the result is an empty string.

 * Time Complexity: O(n)
 * - We traverse the string from right to left once to find the rightmost odd digit, making the time complexity linear in terms of the length of the string.

 * Space Complexity: O(1)
 * - We only use a few variables to track the indices and store the result, resulting in constant space complexity.

 */
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length() - 1;

        // Find the rightmost odd digit
        while (n >= 0) {
            if ((num[n] - '0') % 2 == 1)
                break;
            n--;
        }

        // If no odd digit is found, return an empty string
        if (n == -1) {
            return "";
        }

        // Return the substring from the start to the rightmost odd digit
        return num.substr(0, n + 1);
    }
};
