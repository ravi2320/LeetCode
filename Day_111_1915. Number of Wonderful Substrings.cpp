/*
1915. Number of Wonderful Substrings
Solved
Medium
Topics
Companies
Hint
A wonderful string is a string where at most one letter appears an odd number of times.

For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: word = "aba"
Output: 4
Explanation: The four wonderful substrings are underlined below:
- "aba" -> "a"
- "aba" -> "b"
- "aba" -> "a"
- "aba" -> "aba"
Example 2:

Input: word = "aabb"
Output: 9
Explanation: The nine wonderful substrings are underlined below:
- "aabb" -> "a"
- "aabb" -> "aa"
- "aabb" -> "aab"
- "aabb" -> "aabb"
- "aabb" -> "a"
- "aabb" -> "abb"
- "aabb" -> "b"
- "aabb" -> "bb"
- "aabb" -> "b"
Example 3:

Input: word = "he"
Output: 2
Explanation: The two wonderful substrings are underlined below:
- "he" -> "h"
- "he" -> "e"
 

Constraints:

1 <= word.length <= 105
word consists of lowercase English letters from 'a' to 'j'.
*/

// Intuition:
// This class provides a solution to count the number of wonderful substrings in a given string.
// A wonderful substring is defined as a substring where the count of each character is even
// or at most one character's count is odd. The algorithm uses a bitmask approach to keep track
// of the parity of characters encountered so far. It iterates through the string and updates
// the bitmask accordingly while counting the wonderful substrings.

// Time Complexity: O(N)
// - 'N' is the length of the input string 'word'.
// - The algorithm iterates through each character of the string once.

// Space Complexity: O(N)
// - The algorithm uses a hashmap to store the count of each encountered bitmask.
// - In the worst case, all characters in the string are distinct, so the hashmap can contain 'N' entries.

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    typedef long long ll;

    long long wonderfulSubstrings(string word) {
        unordered_map<ll, ll> mp;

        mp[0] = 1; // Initialize the count of an empty string as 1 (for an empty substring)
        ll mask = 0; // Initialize the bitmask
        ll result = 0; // Initialize the result

        // Iterate through each character in the string
        for (char &ch : word) {
            int shift = ch - 'a'; // Calculate the position of the character in the bitmask
            mask ^= (1LL << shift); // Toggle the corresponding bit in the bitmask

            result += mp[mask]; // Add the count of wonderful substrings with the current bitmask

            // Iterate through each character from 'a' to 'j'
            for (char ch1 = 'a'; ch1 <= 'j'; ch1++) {
                shift = ch1 - 'a'; // Calculate the position of the character in the bitmask

                // Create a new bitmask by toggling the bit corresponding to the current character
                ll check_mask = (mask ^ (1LL << shift));

                // Add the count of wonderful substrings with the new bitmask
                result += mp[check_mask];
            }

            // Increment the count of substrings with the current bitmask
            mp[mask]++;
        }

        // Return the total count of wonderful substrings
        return result;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    string word = "aba";
    long long count = obj.wonderfulSubstrings(word);
    cout << "Count of wonderful substrings: " << count << endl; // Output: Count of wonderful substrings: 4
    return 0;
}
