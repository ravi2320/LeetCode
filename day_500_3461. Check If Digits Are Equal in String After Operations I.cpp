/*
3461. Check If Digits Are Equal in String After Operations I

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given a string s consisting of digits. Perform the following operation repeatedly until the string has exactly two digits:

For each pair of consecutive digits in s, starting from the first digit, calculate a new digit as the sum of the two digits modulo 10.
Replace s with the sequence of newly calculated digits, maintaining the order in which they are computed.
Return true if the final two digits in s are the same; otherwise, return false.

 

Example 1:

Input: s = "3902"

Output: true

Explanation:

Initially, s = "3902"
First operation:
(s[0] + s[1]) % 10 = (3 + 9) % 10 = 2
(s[1] + s[2]) % 10 = (9 + 0) % 10 = 9
(s[2] + s[3]) % 10 = (0 + 2) % 10 = 2
s becomes "292"
Second operation:
(s[0] + s[1]) % 10 = (2 + 9) % 10 = 1
(s[1] + s[2]) % 10 = (9 + 2) % 10 = 1
s becomes "11"
Since the digits in "11" are the same, the output is true.
Example 2:

Input: s = "34789"

Output: false

Explanation:

Initially, s = "34789".
After the first operation, s = "7157".
After the second operation, s = "862".
After the third operation, s = "48".
Since '4' != '8', the output is false.
 

Constraints:

3 <= s.length <= 100
s consists of only digits.
*/

/*
Intuition:
The problem is to check whether the string `s` has the same digits after repeatedly transforming it until the string has two digits left. 
In each transformation, the new string is formed by adding the adjacent digits modulo 10. 

For example:
  "1234" -> "35" (1+2 % 10 = 3, 2+3 % 10 = 5)
  "35" -> "8" (3+5 % 10 = 8)
  
We continue applying this transformation until we are left with two digits. If the two digits are equal, return `true`; otherwise, return `false`.

Time Complexity:
Let n be the length of the string `s`. 
- In the first iteration, we process all `n` digits.
- In the second iteration, the string length is reduced to `n-1`, and so on.
- The number of iterations will be `O(n)`, and in each iteration, we process all elements of the current string.

Thus, the overall time complexity is O(n^2), where n is the length of the input string.

Space Complexity:
The space complexity is O(n) due to the string `s` being reduced step by step, and the temporary string `str` that holds the result of each transformation.

*/

class Solution {
public:
    // Function to check if the string `s` has the same digits after transformations
    bool hasSameDigits(string s) {
        
        // Keep transforming the string until it has 2 digits
        while (s.size() > 2) {
            int n = s.length();  // Get the length of the current string
            string str;  // This will store the transformed string for the next iteration
            
            // Perform the transformation: for each pair of adjacent digits
            for (int i = 1; i < n; i++) {
                // Add the adjacent digits modulo 10
                int num = ((s[i-1] - '0') + (s[i] - '0')) % 10;
                // Push the resulting digit as a character to the new string
                str.push_back(num + '0');
            }
            // Update s to the transformed string
            s = str;
        }

        // Return true if the two remaining digits are the same, false otherwise
        return s[0] == s[1];
    }
};
