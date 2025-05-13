/*
3335. Total Characters in String After Transformations I
Solved
Medium
Topics
Companies
Hint
You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: s = "abcyy", t = 2

Output: 7

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'
String after the first transformation: "bcdzz"
Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.
Example 2:

Input: s = "azbk", t = 1

Output: 5

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'
String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 105
*/

/*
Approach:
- We are given a string `s` and an integer `t` representing the number of transformations.
- Each transformation follows a specific rule:
    - For character 'z', it becomes both 'a' and 'b'.
    - For any other character, say 'c', it becomes the next character in the alphabet, i.e., 'd'.
- We track the frequency of each character using a frequency array of size 26.
- For `t` transformations, we update the frequency array accordingly.

Intuition:
- Instead of transforming the string directly (which can lead to exponential growth),
  we simulate transformations using the frequency count of characters.
- This ensures we stay within time/memory constraints.

Time Complexity: O(t * 26) => effectively O(t)
- For each transformation, we loop over all 26 characters once.

Space Complexity: O(26) => O(1)
- We use constant extra space for two frequency arrays.

*/

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26, 0);  // Frequency array for 'a' to 'z'
        int mod = 1e9 + 7;

        // Initialize the frequency from the input string
        for(char &x : s){
            freq[x - 'a']++;
        }

        // Perform 't' transformations
        for(int i = 0; i < t; i++) {
            vector<int> temp(26, 0);  // Temporary frequency array after transformation

            for(int j = 0; j < 26; j++) {
                if (freq[j]) {
                    if (j == 25) {  // If character is 'z'
                        temp[0] = (temp[0] + freq[25]) % mod;  // becomes 'a'
                        temp[1] = (temp[1] + freq[25]) % mod;  // and 'b'
                    } else {
                        temp[j + 1] = (temp[j + 1] + freq[j]) % mod;  // becomes next char
                    }
                }
            }

            freq = temp;  // Update frequency array for next transformation
        }

        // Calculate total length after all transformations
        int len = 0;
        for(int i = 0; i < 26; i++) {
            len = (len + freq[i]) % mod;
        }

        return len;
    }
};
