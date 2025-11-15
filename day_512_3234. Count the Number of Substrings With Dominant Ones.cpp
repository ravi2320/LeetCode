/*
3234. Count the Number of Substrings With Dominant Ones
Solved

avatar
Discuss Approach
arrow-up
Medium
Topics
premium lock icon
Companies
Hint
You are given a binary string s.

Return the number of substrings with dominant ones.

A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.

 

Example 1:

Input: s = "00011"

Output: 5

Explanation:

The substrings with dominant ones are shown in the table below.

i	j	s[i..j]	Number of Zeros	Number of Ones
3	3	1	0	1
4	4	1	0	1
2	3	01	1	1
3	4	11	0	2
2	4	011	1	2
Example 2:

Input: s = "101101"

Output: 16

Explanation:

The substrings with non-dominant ones are shown in the table below.

Since there are 21 substrings total and 5 of them have non-dominant ones, it follows that there are 16 substrings with dominant ones.

i	j	s[i..j]	Number of Zeros	Number of Ones
1	1	0	1	0
4	4	0	1	0
1	4	0110	2	2
0	4	10110	2	3
1	5	01101	2	3
 

Constraints:

1 <= s.length <= 4 * 104
s consists only of characters '0' and '1'
*/

// Intuition:
// We are given a binary string, and we need to count the number of valid substrings
// that satisfy a certain condition: the number of zeroes squared should be greater than
// or equal to the number of ones in the substring. We need to efficiently check all 
// possible substrings and determine how many of them meet this condition.

// Approach:
// 1. We first calculate the cumulative count of ones up to each index in the string.
// 2. For each substring, we compute the number of ones and zeros. We then check the 
//    condition zeroCnt^2 >= onesCnt. If this is true, we count the substring.
// 3. We optimize by skipping substrings that don't need further checking using "wasteIndices"
//    and adjusting the iteration with extra steps when necessary.

// Time Complexity:
// The outer loop runs in O(n), and the inner loop typically runs in O(n) as well, 
// leading to an overall time complexity of O(n^2) in the worst case.
// However, optimizations within the inner loop (using `j = j + wasteIndices - 1`) 
// might reduce the number of iterations, but the worst-case still holds.

// Space Complexity:
// The space complexity is O(n) due to the use of the `cummOnes` vector to store 
// the cumulative ones count for each index in the string.

class Solution {
public:
    // Function to count valid substrings
    int numberOfSubstrings(string s) {
        int n = s.length();  // Length of the string

        // Step 1: Calculate cumulative count of ones in the string
        vector<int> cummOnes(n, 0);  
        cummOnes[0] = (s[0] == '1') ? 1 : 0;  // Initialize first element based on if it's '1' or '0'

        // Fill in the cumulative ones array
        for (int i = 1; i < n; i++) {
            cummOnes[i] = cummOnes[i - 1] + ((s[i] == '1') ? 1 : 0);
        }

        int res = 0;  // Initialize result counter

        // Step 2: Iterate through all possible substrings
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Calculate the count of ones and zeros in the current substring s[i...j]
                int onesCnt = cummOnes[j] - ((i > 0) ? cummOnes[i - 1] : 0);
                int zeroCnt = (j - i + 1) - onesCnt;  // Zero count is the total length minus ones count

                // Check the condition: zeroCnt^2 > onesCnt
                if (zeroCnt * zeroCnt > onesCnt) {
                    // If the condition holds, we calculate how many indices we can skip
                    int wasteIndices = (zeroCnt * zeroCnt) - onesCnt;
                    j = j + wasteIndices - 1;  // Move `j` forward to skip unnecessary substrings
                } 
                else if (zeroCnt * zeroCnt == onesCnt) {
                    // If the condition holds exactly, count this valid substring
                    res += 1;
                } 
                else {
                    // If zeroCnt^2 < onesCnt, the substring is valid, so we count it
                    res += 1;

                    // Try to skip as many invalid substrings as possible by calculating the extra step
                    int extra = sqrt(onesCnt) - zeroCnt;  // Extra shift needed to optimize
                    int next = j + extra;

                    if (next >= n) {
                        // If the next index goes out of bounds, count all remaining valid substrings
                        res += (n - j - 1);
                        break;
                    } else {
                        // Otherwise, add the extra count to the result
                        res += extra;
                    }

                    j = next;  // Move `j` forward based on the calculated `extra` step
                }
            }
        }

        return res;  // Return the total count of valid substrings
    }
};
