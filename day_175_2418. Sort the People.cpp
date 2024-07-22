/*
2418. Sort the People
Solved
Easy
Topics
Companies
Hint
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.
*/

/**
 * Intuition:
 * 1. **Pairing Names with Heights:** Combine names and heights into pairs.
 * 2. **Sorting:** Sort the pairs in descending order based on heights.
 * 3. **Extracting Names:** Extract the names from the sorted pairs to get the desired order.
 *
 * Time Complexity: O(n log n)
 * - Sorting the pairs dominates the time complexity.
 *
 * Space Complexity: O(n)
 * - We use additional space to store the pairs and the result.
 */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a vector of pairs to hold heights and corresponding names
        vector<pair<int, string>> vec;
        int n = names.size();

        // Combine names and heights into pairs
        for(int i = 0; i < n; i++) {
            vec.push_back({heights[i], names[i]});
        }

        // Sort the pairs in descending order based on heights
        sort(vec.rbegin(), vec.rend());

        // Extract the names from the sorted pairs
        vector<string> ans;
        for(auto &itr : vec) {
            ans.push_back(itr.second);
        }

        return ans;
    }
};
