/*
3170. Lexicographically Minimum String After Removing Stars
Solved
Medium
Topics
premium lock icon
Companies
You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.

 

Example 1:

Input: s = "aaba*"

Output: "aab"

Explanation:

We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

Example 2:

Input: s = "abc"

Output: "abc"

Explanation:

There is no '*' in the string.

 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters and '*'.
The input is generated such that it is possible to delete all '*' characters.
*/

/*
Approach:
- Use a custom min-heap (priority queue) to keep track of characters in the string `s` based on lexicographic order.
- When a '*' is encountered, pop the smallest character (based on custom comparator) and mark it for deletion.
- After processing the string, construct the result by skipping all characters marked with '*'.

Intuition:
- Every '*' deletes the smallest lexicographically previous character.
- Using a min-heap allows efficient retrieval of the smallest character before each '*'.
- Mark deleted characters as '*' to avoid shifting the entire string, then filter them in the final result.

Time Complexity: O(N * log N)
- N = length of the string.
- Each insertion and deletion in the priority queue takes O(log N).

Space Complexity: O(N)
- Space used by the priority queue and result string.
*/

class Solution {
    typedef pair<char, int> P; // Pair of character and its index
public:
    // Custom comparator for min-heap based on lexicographic order and index
    struct comp {
        bool operator()(P &p1, P &p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second; // Keep later occurrence for same character
            }
            return p1.first > p2.first; // Min-heap by character
        }
    };

    string clearStars(string s) {
        int n = s.length();
        priority_queue<P, vector<P>, comp> pq; // Min-heap based on custom comparator

        // Traverse the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                // If star is found, remove the smallest character before it
                if (!pq.empty()) {
                    int idx = pq.top().second;
                    s[idx] = '*'; // Mark the character as deleted
                    pq.pop();
                }
            } else {
                pq.push({s[i], i}); // Push character with its index
            }
        }

        // Build final result string
        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};
