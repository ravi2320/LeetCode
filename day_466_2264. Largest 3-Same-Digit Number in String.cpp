/*
2264. Largest 3-Same-Digit Number in String

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
 

Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
 

Constraints:

3 <= num.length <= 1000
num only consists of digits.
*/

// Approach:
// 1. Traverse the string `num` from index 2 to the end.
// 2. At each step, check if the current character and the previous two characters are the same.
// 3. If they are, extract the 3-character substring starting from (i - 2).
// 4. Keep track of the lexicographically largest such substring using `max()`.
// 5. Return the largest substring found, or an empty string if none is found.
//
// Intuition:
// The problem asks for the largest "good integer"—a substring of length 3 made of the same digit.
// Since digits are characters, comparing them lexicographically also preserves numeric ordering.
// By checking every possible triplet in a single pass, we efficiently find the largest match.
//
// Time Complexity:
// O(n) — We iterate through the string once, performing O(1) work for each index.
// Space Complexity:
// O(1) — Only a constant amount of extra space is used.

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();  // Length of the input string
        string ans = "";       // Stores the largest good integer found

        // Loop starts from index 2 to check triplets
        for (int i = 2; i < n; i++) {
            // Check if the last three characters are identical
            if (num[i-2] == num[i-1] && num[i-1] == num[i]) {
                // Update ans with the lexicographically larger substring
                ans = max(ans, num.substr(i-2, 3));
            }
        }

        return ans; // Return the largest good integer found
    }
};
