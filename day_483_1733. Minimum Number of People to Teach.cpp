/*
1733. Minimum Number of People to Teach

On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

You are given an integer n, an array languages, and an array friendships where:

There are n languages numbered 1 through n,
languages[i] is the set of languages the i​​​​​​th​​​​ user knows, and
friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​i​​​​​ and vi.
You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.
 

Example 1:

Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
Output: 1
Explanation: You can either teach user 1 the second language or user 2 the first language.
Example 2:

Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
Output: 2
Explanation: Teach the third language to users 1 and 3, yielding two users to teach.
 

Constraints:

2 <= n <= 500
languages.length == m
1 <= m <= 500
1 <= languages[i].length <= n
1 <= languages[i][j] <= n
1 <= u​​​​​​i < v​​​​​​i <= languages.length
1 <= friendships.length <= 500
All tuples (u​​​​​i, v​​​​​​i) are unique
languages[i] contains only unique values
*/

/*
Approach:
1. Identify which people cannot communicate:
   - For each friendship (u, v), check if they share a common language.
   - If they don't, both u and v must be considered "sadPeoples" (need teaching).
2. Among sadPeoples, find the language that is already spoken by the maximum number of them.
   - Count frequency of each language spoken by sadPeoples.
   - The best strategy is to teach this most common language to the rest of sadPeoples.
3. Answer = (number of sadPeoples) - (max frequency of a single language among them).

Intuition:
- Only people who cannot communicate with their friends need teaching.
- To minimize teachings, we should teach everyone the same language.
- Naturally, picking the language most common among sadPeoples minimizes additional effort.

Time Complexity:  
- Checking friendships: O(F * L)  
  (F = number of friendships, L = avg languages per person)  
- Counting languages: O(S * L)  
  (S = number of sadPeoples)  
Overall: O(F * L + S * L), efficient enough.

Space Complexity:  
- O(S + L)  
  (Set of sadPeoples and map for language frequency).
*/

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadPeoples;

        // Step 1: Find people who cannot communicate with their friends
        for(int i = 0; i < friendships.size(); i++) {
            int u = friendships[i][0] - 1; // convert to 0-index
            int v = friendships[i][1] - 1;

            // Create a set of languages for person u
            unordered_set<int> langSet(languages[u].begin(), languages[u].end());

            bool canTalk = false;
            // Check if v shares a language with u
            for(int &lang : languages[v]) {
                if(langSet.count(lang)) {
                    canTalk = true;
                    break; // no need to check further
                }
            }

            // If they cannot talk, mark them as "sad"
            if(!canTalk) {
                sadPeoples.insert(u);
                sadPeoples.insert(v);
            }
        }   

        // Step 2: Count frequency of each language spoken among sadPeoples
        int maxTalkLanguage = 0;
        unordered_map<int, int> langFreq;

        for(int person : sadPeoples) {
            for(int &lang : languages[person]) {
                langFreq[lang]++;
                maxTalkLanguage = max(maxTalkLanguage, langFreq[lang]);
            }
        }

        // Step 3: Teach everyone in sadPeoples the most common language
        return sadPeoples.size() - maxTalkLanguage;
    }
};
