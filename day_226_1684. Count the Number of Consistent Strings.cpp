/*
1684. Count the Number of Consistent Strings
Solved
Easy
Topics
Companies
Hint
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
*/

/*
Approach:
1. The task is to count the number of "consistent" strings from the given `words` list.
2. A string is considered consistent if every character in it is present in the `allowed` string.
3. First, we create a frequency map (`mp`) for the characters in the `allowed` string.
   - The map tracks which characters are allowed.
4. Then, for each string in the `words` list, we check if all characters of the string are present in the `allowed` set (using the `mp` array).
5. If all characters are valid (i.e., consistent with `allowed`), increment the count.

Time Complexity:
- O(n * m), where `n` is the number of strings in `words` and `m` is the average length of each string.
   - We loop over all characters in each string to check consistency.

Space Complexity:
- O(1), since the `mp` array is always of fixed size 26 (for lowercase English letters).

*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a map to track allowed characters
        vector<int> mp(26, 0);

        // Mark the allowed characters in the frequency map
        for (char &x : allowed) {
            mp[x - 'a']++;
        }

        int cnt = 0;  // To count consistent strings
        
        // Iterate over each word in the list
        for (string str : words) {
            bool flag = true;  // Assume the word is consistent
            
            // Check if all characters in the word are allowed
            for (char &x : str) {
                if (!mp[x - 'a']) {  // If any character is not allowed
                    flag = false;     // Mark the word as inconsistent
                    break;            // Stop checking further characters
                }
            }

            if (flag) cnt++;  // If the word is consistent, increment the count
        }

        return cnt;  // Return the total number of consistent strings
    }
};
