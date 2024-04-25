/*
2370. Longest Ideal Subsequence
Solved
Medium
Topics
Companies
Hint
You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.

 

Example 1:

Input: s = "acfgbd", k = 2
Output: 4
Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
Example 2:

Input: s = "abcd", k = 3
Output: 4
Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.
 

Constraints:

1 <= s.length <= 105
0 <= k <= 25
s consists of lowercase English letters.
*/

// Intuition:
// This class provides a solution to find the length of the longest ideal string that can be formed
// by deleting characters from the given string 's'. Two characters are considered ideal if their
// absolute difference in ASCII values is less than or equal to 'k'. The algorithm uses dynamic
// programming to compute the length of the longest ideal string.

// Time Complexity: O(n^2)
// - 'n' is the length of the input string 's'.
// - The algorithm iterates through each character of the string and, for each character,
//   iterates through all previous characters to compute the length of the longest ideal string,
//   resulting in a time complexity of O(n^2).

// Space Complexity: O(n)
// - The algorithm uses an additional array 'dp' of size 'n' to store the length of the longest ideal
//   string ending at each position.

#include <string>
#include <vector>
#include <algorithm>
#include <cmath> // For abs function
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> dp(n, 1); // Initialize an array to store the length of the longest ideal string ending at each position
        int res = 1; // Initialize the result to 1 (minimum length of an ideal string)

        // Iterate through each character of the string
        for (int i = 1; i < n; i++) {
            // Iterate through all previous characters
            for (int j = i - 1; j >= 0; j--) {
                // Check if the absolute difference in ASCII values is less than or equal to 'k'
                if (abs(s[i] - s[j]) <= k)
                    // Update the length of the longest ideal string ending at position 'i'
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            // Update the overall maximum length of the longest ideal string
            res = max(res, dp[i]);
        }
        // Return the length of the longest ideal string
        return res;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    string s = "abcde";
    int k = 2;
    cout << "Length of the longest ideal string: " << obj.longestIdealString(s, k) << endl; // Output: 3
    return 0;
}



// Intuition:
// This class provides a solution to find the length of the longest ideal string that can be formed
// by deleting characters from the given string 's'. Two characters are considered ideal if their
// absolute difference in ASCII values is less than or equal to 'k'. The algorithm uses dynamic
// programming to compute the length of the longest ideal string.

// Time Complexity: O(n)
// - 'n' is the length of the input string 's'.
// - The algorithm iterates through each character of the string once, resulting in a time complexity of O(n).

// Space Complexity: O(1) [Fixed size, independent of input]
// - The algorithm uses an additional array 'dp' of size 26 to store the length of the longest ideal
//   string ending at each character position.

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> dp(26, 0); // Initialize an array to store the length of the longest ideal string ending at each character position
        int res = 0; // Initialize the result to 0

        // Iterate through each character of the string
        for (int i = 0; i < n; i++) {
            int curr = s[i] - 'a'; // Get the index of the current character
            int left = max(0, curr - k); // Calculate the left boundary of the ideal range
            int right = min(25, curr + k); // Calculate the right boundary of the ideal range

            int longest = 0; // Initialize the length of the longest ideal string for the current character
            // Iterate through the ideal range and find the maximum length of the ideal string
            for (int j = left; j <= right; j++) {
                longest = max(longest, dp[j]);
            }
            // Update the length of the longest ideal string ending at the current character position
            dp[curr] = max(dp[curr], longest + 1);
            // Update the overall maximum length of the longest ideal string
            res = max(res, dp[curr]);
        }

        // Return the length of the longest ideal string
        return res;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    string s = "abcde";
    int k = 2;
    cout << "Length of the longest ideal string: " << obj.longestIdealString(s, k) << endl; // Output: 3
    return 0;
}
