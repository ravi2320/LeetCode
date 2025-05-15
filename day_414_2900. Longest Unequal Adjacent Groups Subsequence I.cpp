/*
2900. Longest Unequal Adjacent Groups Subsequence I
Solved
Easy
Topics
Companies
Hint
You are given a string array words and a binary array groups both of length n, where words[i] is associated with groups[i].

Your task is to select the longest alternating subsequence from words. A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements in the binary array groups differ. Essentially, you are to choose strings such that adjacent elements have non-matching corresponding bits in the groups array.

Formally, you need to find the longest subsequence of an array of indices [0, 1, ..., n - 1] denoted as [i0, i1, ..., ik-1], such that groups[ij] != groups[ij+1] for each 0 <= j < k - 1 and then find the words corresponding to these indices.

Return the selected subsequence. If there are multiple answers, return any of them.

Note: The elements in words are distinct.

 

Example 1:

Input: words = ["e","a","b"], groups = [0,0,1]

Output: ["e","b"]

Explanation: A subsequence that can be selected is ["e","b"] because groups[0] != groups[2]. Another subsequence that can be selected is ["a","b"] because groups[1] != groups[2]. It can be demonstrated that the length of the longest subsequence of indices that satisfies the condition is 2.

Example 2:

Input: words = ["a","b","c","d"], groups = [1,0,1,1]

Output: ["a","b","c"]

Explanation: A subsequence that can be selected is ["a","b","c"] because groups[0] != groups[1] and groups[1] != groups[2]. Another subsequence that can be selected is ["a","b","d"] because groups[0] != groups[1] and groups[1] != groups[3]. It can be shown that the length of the longest subsequence of indices that satisfies the condition is 3.

 

Constraints:

1 <= n == words.length == groups.length <= 100
1 <= words[i].length <= 10
groups[i] is either 0 or 1.
words consists of distinct strings.
words[i] consists of lowercase English letters.
*/

/*
Approach:
- We are given a list of `words` and a corresponding list `groups`, where each group is either 0 or 1.
- We need to construct the **longest subsequence** of `words` such that the group IDs alternate between 0 and 1.

Intuition:
- Start by picking the first word.
- Then, for each next word, only include it if its group is **different** from the previous included word’s group.
- Alternate group values ensure a valid subsequence.

Example:
  words  = ["a", "b", "c", "d", "e"]
  groups = [ 0 ,  0 , 1 , 1 , 0 ]
  Output = ["a", "c", "e"]

Time Complexity: O(n), where n is the number of elements in `groups`
Space Complexity: O(k), where k is the size of resulting subsequence (at most n)
*/

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<string> res;

        // Always start with the first word
        res.push_back(words[0]);
        int prev = groups[0]; // Store the group of the last selected word

        for (int i = 1; i < n; i++) {
            // Only add the word if group alternates from previous
            if (groups[i] != prev) {
                res.push_back(words[i]);
                prev = groups[i]; // Update previous to current group
            }
        }

        return res;
    }
};
