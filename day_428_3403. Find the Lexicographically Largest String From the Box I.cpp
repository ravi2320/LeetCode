/*
3403. Find the Lexicographically Largest String From the Box I
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a string word, and an integer numFriends.

Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
All the split words are put into a box.
Find the lexicographically largest string from the box after all the rounds are finished.

 

Example 1:

Input: word = "dbca", numFriends = 2

Output: "dbc"

Explanation: 

All possible splits are:

"d" and "bca".
"db" and "ca".
"dbc" and "a".
Example 2:

Input: word = "gggg", numFriends = 4

Output: "g"

Explanation: 

The only possible split is: "g", "g", "g", and "g".

 

Constraints:

1 <= word.length <= 5 * 103
word consists only of lowercase English letters.
1 <= numFriends <= word.length
*/

/*
Approach:
- We want to divide the given string `word` among `numFriends` friends, where each friend gets at least 1 character.
- So the maximum length of a substring one friend can get is `n - (numFriends - 1)`.
- We are to return the lexicographically greatest string of that possible length.
- Slide a window of length `possibleLength` across the string, and return the maximum substring.

Intuition:
- Since we must divide the string among `numFriends` and give each friend at least one character,
  the first friend can receive at most `n - (numFriends - 1)` characters.
- Among all substrings of that length, we choose the lexicographically greatest one.

Time Complexity: O(n * k), where k = possibleLength
- We evaluate at most n substrings of length up to k.

Space Complexity: O(k)
- For storing the result substring.
*/

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();

        // If only one friend, return the entire word
        if(numFriends == 1)
            return word;

        // Max length one friend can get
        int possibleLength = n - (numFriends - 1);

        // Start with the first possible substring
        string res = word.substr(0, possibleLength);

        // Slide a window of length `possibleLength` and find max lexicographic substring
        for(int i = 1; i <= n - possibleLength; i++) {
            string candidate = word.substr(i, possibleLength);
            res = max(res, candidate);
        }

        return res;
    }
};


/*
Approach:
- We need to divide the string `word` into parts such that each of the `numFriends` gets at least 1 character.
- Hence, the maximum number of characters one friend can receive is `n - (numFriends - 1)`.
- To get the lexicographically greatest substring of this possible length:
    1. Build a frequency map (vector of positions) for each character 'a' to 'z'.
    2. Start from the highest character ('z') and check all its positions in the string.
    3. For each position, try to take a substring of length `lengthPossible`, bounded by the end of the string.
    4. Among all such substrings, pick the lexicographically greatest one.

Intuition:
- Since we only care about the maximum lexicographical substring of a fixed length,
  it makes sense to prioritize positions of the highest characters first.
- Once the best character's positions are found, check what substring can be formed starting from each of them.

Time Complexity: O(n * k)
- Constructing the frequency map takes O(n).
- For each position of the max character (could be up to n), extracting substring takes O(k), where k is max possible length.

Space Complexity: O(n)
- To store frequency positions of each character and the result string.
*/

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();

        // If there's only one friend, return the whole string
        if(numFriends == 1)
            return word;

        // Max length a single friend can get
        int lengthPossible = n - (numFriends - 1);

        // Frequency map: freq[c] stores all positions of character 'a'+c in the string
        vector<vector<int>> freq(26);
        for(int i = 0; i < n; i++) {
            freq[word[i] - 'a'].push_back(i);
        }

        // Find the highest character in the string
        int idx = -1;
        for(int i = 25; i >= 0; i--) {
            if(!freq[i].empty()) {
                idx = i;
                break;
            }
        }

        // Try all substrings starting from positions of the highest character
        string res = "";
        for(int i : freq[idx]) {
            int canTakeLength = min(lengthPossible, n - i); // bound check
            res = max(res, word.substr(i, canTakeLength));
        }

        return res;
    }
};
