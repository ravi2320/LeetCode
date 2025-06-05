/*
1061. Lexicographically Smallest Equivalent String
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'.
Symmetry: 'a' == 'b' implies 'b' == 'a'.
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

 

Example 1:

Input: s1 = "parker", s2 = "morris", baseStr = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
The characters in each group are equivalent and sorted in lexicographical order.
So the answer is "makkek".
Example 2:

Input: s1 = "hello", s2 = "world", baseStr = "hold"
Output: "hdld"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".
Example 3:

Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
Output: "aauaaaaada"
Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".
 

Constraints:

1 <= s1.length, s2.length, baseStr <= 1000
s1.length == s2.length
s1, s2, and baseStr consist of lowercase English letters.
*/

/*
Approach:
- Build a graph where each character in s1 is connected to its equivalent character in s2 (undirected).
- For each character in baseStr, run DFS to find the lexicographically smallest character in its connected component.
- Replace the character with the smallest one found in that component.

Intuition:
- Characters that are equivalent (directly or transitively) form a connected component.
- Since any character in a component can be replaced with another, we aim to find the smallest lexicographic character from that group for substitution.
- DFS is used to explore the component and determine the smallest equivalent character.

Time Complexity: O(N + 26²)
- N = length of s1 or s2.
- At most 26 characters (a-z), hence at most 26x26 connections. Each DFS runs in O(26) in worst case.

Space Complexity: O(26 + N)
- O(26) for the adjacency map and visited array.
- O(N) for the result string.
*/

class Solution {
public:
    // DFS to find the lexicographically smallest character in the component
    char minCharDFS(char curr_ch, unordered_map<char, vector<char>> &adj, vector<int> &vis){
        vis[curr_ch - 'a'] = 1;

        char minChar = curr_ch;
        for(char &ngbr : adj[curr_ch]){
            // If not visited, explore neighbor
            if(vis[ngbr - 'a'] == 0){
                // Take the minimum of current and the result of DFS on neighbor
                minChar = min(minChar, minCharDFS(ngbr, adj, vis));
            }
        }

        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();
        
        unordered_map<char, vector<char>> adj; // Graph representation

        // Build bidirectional graph for equivalence relationships
        for(int i=0; i<n; i++){
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string res;

        // For each character in baseStr, find the smallest equivalent character
        for(int i=0; i<m; i++){
            vector<int> vis(26, 0); // Visited array for DFS

            char minChar = minCharDFS(baseStr[i], adj, vis); // Get smallest character in component
            res.push_back(minChar); // Add to result
        }

        return res;
    }
};
