/*
127. Word Ladder
Solved
Hard
Topics
Companies
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

// Intuition:
// This class provides a solution to transform one string into another by changing one character at a time.
// It employs a breadth-first search (BFS) approach to explore all possible transformations until the target string is reached.

// Time Complexity: O(n * m * 26)
// - 'n' is the length of the input strings A and B.
// - 'm' is the number of words in the dictionary C.
// - Each transformation involves iterating through the characters of the strings, which takes O(n) time.
// - For each transformation, there are at most 26 possibilities for changing each character.
// - Overall time complexity is O(n * m * 26).

// Space Complexity: O(m)
// - The space complexity is dominated by the unordered_set storing the words in the dictionary C, which requires O(m) space.
// - Additionally, the queue used in BFS can contain up to O(n) elements at a time.

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int solve(string A, string B, vector<string> &C) {
        int n = A.size();
        int level = 0;
        
        // Create a set to store words in the dictionary
        unordered_set<string> st(C.begin(), C.end());
        
        // If the target word B is not in the dictionary, return 0
        if (st.find(B) == st.end())
            return 0;
            
        // Create a queue for BFS and add the starting word A
        queue<string> q;
        q.push(A);
        st.erase(A);
        
        while (!q.empty()) {
            int size = q.size();
            level++;
            
            // Process all words at the current level
            while (size--) {
                string original = q.front();
                q.pop();
                
                // If the current word is the target word B, return the level
                if (original == B)
                    return level;
                    
                // Generate all possible transformations of the current word
                for (int i = 0; i < n; i++) {
                    string curr = original;
                    
                    // Try changing each character of the word to all possible lowercase letters
                    for (char c = 'a'; c <= 'z'; c++) {
                        curr[i] = c;
                        
                        // If the transformed word is in the dictionary and different from the original word
                        if (st.find(curr) != st.end()) {
                            if (curr != original) {
                                q.push(curr);
                                st.erase(curr);
                            }
                        }
                    }
                }
            }
        }
        
        // If the target word B is not reachable from A, return 0
        return 0;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    string A = "hit";
    string B = "cog";
    vector<string> C = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << "Minimum transformations required: " << obj.solve(A, B, C) << endl; // Output: 5
    return 0;
}
