/*
1079. Letter Tile Possibilities
Solved
Medium
Topics
Companies
Hint
You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: tiles = "AAABBC"
Output: 188
Example 3:

Input: tiles = "V"
Output: 1
 

Constraints:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.
*/

class Solution {
    int n;

public:
    /**
     * Approach:
     * - Use **backtracking** to generate all possible sequences of the given tiles.
     * - Maintain a **boolean array** (`used`) to track whether a tile is used.
     * - Use a **set (`res`)** to store unique sequences and avoid duplicates.
     * - Recursively explore all possibilities by picking each unused tile one by one.
     *
     * Intuition:
     * - By treating the problem as permutations of characters with repetition, we generate all possible sequences.
     * - The **unordered_set** ensures that duplicate sequences are counted only once.
     * - The base case inserts each formed sequence into the set, ensuring uniqueness.
     *
     * Time Complexity:
     * - Worst case: **O(N!)** (Factorial growth due to permutations)
     * - Since pruning occurs for duplicates, the exact count depends on input uniqueness.
     *
     * Space Complexity:
     * - **O(N!)** for storing unique permutations in the set.
     * - **O(N)** recursion depth due to backtracking.
     */

    void solve(string &tiles, string &curr, vector<bool> &used, unordered_set<string> &res) {
        res.insert(curr); // Store the current sequence

        for (int i = 0; i < n; i++) {
            if (used[i]) continue; // Skip already used tiles

            used[i] = true;
            curr.push_back(tiles[i]); // Add the tile to the sequence

            solve(tiles, curr, used, res); // Recurse for the next position

            curr.pop_back(); // Backtrack
            used[i] = false;  // Mark tile as unused for other paths
        }
    }

    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector<bool> used(n, false); // Track used tiles
        unordered_set<string> res;   // Store unique sequences

        string curr = "";
        solve(tiles, curr, used, res);

        return res.size() - 1; // Exclude the empty string from count
    }
};


class Solution {
public:
    /**
     * Approach:
     * - Use **backtracking** to generate all possible sequences of the given tiles.
     * - Store the count of each character in a **frequency vector (`vec`)** of size 26.
     * - Recursively pick each available tile, decrement its frequency, and explore further.
     * - Restore the frequency count after backtracking.
     *
     * Intuition:
     * - Instead of generating all unique permutations explicitly, we count all possible selections.
     * - The `vec` array ensures we do not consider duplicate permutations.
     * - We count valid sequences by recursively choosing each character and keeping track of visited paths.
     *
     * Time Complexity:
     * - Worst case: **O(N!)** (Factorial growth due to permutations)
     * - Since pruning occurs using frequency tracking, the actual count depends on character uniqueness.
     *
     * Space Complexity:
     * - **O(1)** (Only uses a fixed-size `vec` of length 26)
     * - **O(N)** recursion depth due to backtracking.
     */

    void solve(vector<int> &vec, int &cnt) {
        cnt++; // Count the current valid sequence

        for (int i = 0; i < 26; i++) {
            if (vec[i] == 0) continue; // Skip unavailable characters

            vec[i]--;       // Use the character
            solve(vec, cnt); // Recurse for the next position
            vec[i]++;       // Restore character count for backtracking
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> vec(26, 0); // Frequency array for characters
        int cnt = 0;            // Store count of unique sequences

        // Fill frequency array
        for (char &x : tiles) {
            vec[x - 'A']++;
        }

        solve(vec, cnt);

        return cnt - 1; // Exclude the empty sequence from count
    }
};
