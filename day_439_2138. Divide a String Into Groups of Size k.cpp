/*
2138. Divide a String Into Groups of Size k
Solved

avatar
Discuss Approach
arrow-up
Easy
Topics
premium lock icon
Companies
Hint
A string s can be partitioned into groups of size k using the following procedure:

The first group consists of the first k characters of the string, the second group consists of the next k characters of the string, and so on. Each element can be a part of exactly one group.
For the last group, if the string does not have k characters remaining, a character fill is used to complete the group.
Note that the partition is done so that after removing the fill character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be s.

Given the string s, the size of each group k and the character fill, return a string array denoting the composition of every group s has been divided into, using the above procedure.

 

Example 1:

Input: s = "abcdefghi", k = 3, fill = "x"
Output: ["abc","def","ghi"]
Explanation:
The first 3 characters "abc" form the first group.
The next 3 characters "def" form the second group.
The last 3 characters "ghi" form the third group.
Since all groups can be completely filled by characters from the string, we do not need to use fill.
Thus, the groups formed are "abc", "def", and "ghi".
Example 2:

Input: s = "abcdefghij", k = 3, fill = "x"
Output: ["abc","def","ghi","jxx"]
Explanation:
Similar to the previous example, we are forming the first three groups "abc", "def", and "ghi".
For the last group, we can only use the character 'j' from the string. To complete this group, we add 'x' twice.
Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".
 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters only.
1 <= k <= 100
fill is a lowercase English letter.
*/

/*
Approach:
We are given a string `s`, an integer `k`, and a character `fill`. 
The task is to divide the string into groups of size `k`. If the last group has fewer than `k` characters, 
it should be filled with the `fill` character to make its length `k`.

Steps:
1. Traverse the string in increments of `k` and take substrings of length `k`.
2. If the last group has fewer than `k` characters, append the `fill` character until its length is `k`.

Intuition:
This is a direct simulation problem. The only edge case is the last group, which may need padding.

Time Complexity: O(n)
- We traverse the string once and create substrings of length `k`.

Space Complexity: O(n)
- For storing the result vector of strings
*/

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> res;

        // Step 1: Create substrings of size k
        for (int i = 0; i < n; i += k) {
            string str = s.substr(i, k);
            res.push_back(str);
        }

        // Step 2: Pad the last substring if needed
        string str = res.back();  // Get the last substring
        res.pop_back();           // Remove it temporarily

        // If the last group is not of size k, pad it with fill character
        if (str.size() < k) {
            for (int i = str.size(); i < k; i++) {
                str.push_back(fill);
            }
        }

        res.push_back(str);  // Add the last (possibly padded) group back

        return res;
    }
};
