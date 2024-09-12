/*
1781. Sum of Beauty of All Substrings
Solved
Medium
Topics
Companies
Hint
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters
*/

/*
Approach:
1. The problem requires calculating the "beauty" of every substring of the given string `s`.
   - The beauty of a substring is defined as the difference between the frequency of the most frequent character and the least frequent character (ignoring characters with zero frequency).
2. For each starting index `i`, we iterate through the possible ending indices `j` to consider all substrings starting at `i`.
3. For each substring, we use a frequency map `mp` to track the frequency of each character (indexed from 'a' to 'z').
4. The helper function `findBeauty` computes the beauty of the substring by finding the maximum and minimum frequencies in the current frequency map.
5. We sum the beauty for all substrings and return the total.

Time Complexity:
- O(n^2 * 26) = O(n^2): 
  - There are O(n^2) substrings, and for each substring, we compute the beauty by checking the frequency of all 26 characters.

Space Complexity:
- O(26) = O(1): We use a fixed-size array of size 26 to store character frequencies for each substring.

*/

class Solution {
public:
    // Helper function to calculate the beauty of a substring based on character frequencies
    int findBeauty(vector<int> &mp) {
        int mn = INT_MAX, mx = INT_MIN;

        // Iterate over all 26 possible characters (a to z)
        for (int i = 0; i < 26; i++) {
            if (mp[i] != 0) {
                mn = min(mn, mp[i]);  // Find the minimum non-zero frequency
                mx = max(mx, mp[i]);  // Find the maximum frequency
            }
        }

        return mx - mn;  // Beauty is the difference between max and min frequency
    }

    // Function to calculate the total beauty sum for all substrings of the string `s`
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;  // Store the total beauty sum
        
        // Iterate over all possible starting points of substrings
        for (int i = 0; i < n; i++) {
            vector<int> mp(26, 0);  // Frequency map for characters in the current substring

            // Iterate over possible ending points for substrings starting at `i`
            for (int j = i; j < n; j++) {
                mp[s[j] - 'a']++;  // Update the frequency of the current character
                ans += findBeauty(mp);  // Add the beauty of the current substring to the total
            }
        }

        return ans;  // Return the total beauty sum
    }
};
