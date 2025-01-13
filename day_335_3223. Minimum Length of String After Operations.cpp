/*
3223. Minimum Length of String After Operations
Solved
Medium
Topics
Companies
Hint
You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest character to the left of index i that is equal to s[i].
Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.

 

Example 1:

Input: s = "abaacbcbb"

Output: 5

Explanation:
We do the following operations:

Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".
Example 2:

Input: s = "aa"

Output: 2

Explanation:
We cannot perform any operations, so we return the length of the original string.

 

Constraints:

1 <= s.length <= 2 * 105
s consists only of lowercase English letters.
*/

/*
Approach:
1. Traverse the string and maintain a frequency array (`freq`) to count occurrences of each character.
2. Each time a character's frequency reaches 3:
   - Remove 2 instances of that character (i.e., reduce the count by 2).
   - Increment the `deleted` counter by 2 to track the number of removed characters.
3. At the end of the traversal, the minimum length of the string is calculated as:
   - Original length of the string (`n`) minus the total number of deleted characters.

Intuition:
- To minimize the string length, remove characters when their frequency reaches 3, as these contribute redundantly to the string.

Time Complexity:
- \(O(n)\): Single pass through the string, with \(O(1)\) operations for frequency updates.

Space Complexity:
- \(O(26) = O(1)\): Fixed-size array to store character frequencies.

Edge Cases:
1. If the string is empty, return 0.
2. Handles strings with no characters reaching a frequency of 3.

*/

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length(); // Length of the original string
        int deleted = 0;    // Counter for the number of deleted characters
        vector<int> freq(26, 0); // Frequency array to count occurrences of each character

        // Traverse the string and update frequencies
        for (char &x : s) {
            freq[x - 'a']++; // Increment frequency of the current character

            // If frequency of a character reaches 3, remove 2 instances
            if (freq[x - 'a'] == 3) {
                freq[x - 'a'] -= 2; // Remove 2 instances
                deleted += 2;      // Increment the deleted counter
            }
        }

        // Return the minimum length of the string after deletions
        return n - deleted;
    }
};


/*
Approach:
1. Use a frequency array (`freq`) to count occurrences of each character in the string.
2. For each character:
   - If its frequency is greater than 0:
     - Add 1 to the result if the frequency is odd (to account for the minimum length needed to include this character).
     - Add 2 if the frequency is even (to include a pair of the character).
3. Return the final accumulated result (`res`).

Intuition:
- The goal is to calculate the minimum string length such that characters can be paired optimally.
- If a character appears an odd number of times, at least 1 instance of it must remain in the string.
- If a character appears an even number of times, all occurrences can be paired.

Time Complexity:
- \(O(n + 26) = O(n)\): Traverse the string once to calculate frequencies (\(O(n)\)) and then iterate through the 26 letters (\(O(26)\)).

Space Complexity:
- \(O(26) = O(1)\): Fixed-size array for frequency tracking.

Edge Cases:
1. Empty string: Result is 0.
2. All characters are unique: Result equals the string length.

*/

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0); // Frequency array to count character occurrences

        // Populate the frequency array
        for (char &x : s) {
            freq[x - 'a']++;
        }

        int res = 0; // Result to store the minimum length

        // Calculate the contribution of each character
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                res += (freq[i] % 2 == 0) ? 2 : 1; // Add 2 for even, 1 for odd frequency
            }
        }

        return res; // Return the calculated minimum length
    }
};
