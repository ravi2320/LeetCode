/*
763. Partition Labels
Solved
Medium
Topics
Companies
Hint
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

/*
Approach:
1. **Precompute Last Occurrences**: Store the last index of each character in the string.
2. **Iterate Over the String**: Maintain a variable `end` to track the farthest last occurrence of characters in the current partition.
3. **Partition Creation**: When the current index reaches `end`, it means the partition can be completed.
4. **Store Partition Length**: Add the partition size to the result and update the `start` index for the next partition.

Intuition:
- Each partition must contain all occurrences of its characters.
- The farthest last occurrence of a character determines the partition's end.
- By iterating through the string and expanding `end`, we efficiently find partitions.

Time Complexity: **O(n)** - We traverse the string twice.
Space Complexity: **O(1)** - Uses a fixed-size array for character frequencies.
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        
        // Step 1: Store the last occurrence of each character
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<int> res;
        int end = 0, start = -1;
        
        // Step 2: Traverse and form partitions
        for (int j = 0; j < n; j++) {
            end = max(end, lastIndex[s[j] - 'a']); // Update the farthest last occurrence

            if (j == end) { // Partition found
                res.push_back(j - start);
                start = j; // Update start for next partition
            }
        }

        return res;
    }
};
