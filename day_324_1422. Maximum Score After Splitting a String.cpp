/*
1422. Maximum Score After Splitting a String
Solved
Easy
Topics
Companies
Hint
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

 

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3
Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3:

Input: s = "1111"
Output: 3
 

Constraints:

2 <= s.length <= 500
The string s consists of characters '0' and '1' only.
*/

/*
Approach:
1. The problem involves dividing the string into two non-empty parts and maximizing the sum of zeros in the left part and ones in the right part.
2. Use a nested loop:
   - Outer loop iterates over possible split points.
   - Inner loops count zeros in the left part and ones in the right part for each split.
3. Keep track of the maximum sum of zeros and ones encountered.

Intuition:
To maximize the score, we want the left substring to contain as many zeros as possible and the right substring to contain as many ones as possible. By iterating over all possible splits, we ensure we check all valid divisions.

Time Complexity:
- Outer loop runs O(N - 1), where N is the string's length.
- For each split, counting zeros and ones takes O(N), resulting in O(N^2) overall.

Space Complexity:
- Only integer variables are used, resulting in O(1) additional space.

*/

class Solution {
public:
    int maxScore(string s) {
        int n = s.length(); // Length of the string
        int ans = INT_MIN;  // Initialize the maximum score to a very low value

        // Iterate over all possible split points
        for (int i = 0; i < n - 1; i++) {
            int zero = 0, one = 0; // Initialize counts of zeros and ones

            // Count zeros in the left part of the split
            for (int j = 0; j <= i; j++) {
                if (s[j] == '0') {
                    zero++;
                }
            }

            // Count ones in the right part of the split
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '1') {
                    one++;
                }
            }

            // Update the maximum score
            ans = max(ans, zero + one);
        }

        return ans; // Return the maximum score
    }
};

/*
Approach:
1. Precompute the total number of ones in the string.
2. Iterate through the string while maintaining counts of zeros and ones for the left substring up to the current index.
3. For each split point, compute the score as:
   - Zeros in the left part (`zero`) + Ones in the right part (`totalOne - one`).
4. Keep track of the maximum score encountered.

Intuition:
Instead of recalculating the number of zeros and ones for every split, use a running count for zeros and ones. This optimization reduces redundant computations and improves efficiency.

Time Complexity:
- Precomputing the total number of ones: O(N), where N is the length of the string.
- Iterating through the string to calculate scores: O(N).
Overall: O(N).

Space Complexity:
- Only integer variables are used for counts and results, resulting in O(1) additional space.

*/

class Solution {
public:
    int maxScore(string s) {
        int n = s.length(); // Length of the string
        int totalOne = 0;   // Total count of ones in the string

        // Precompute the total number of ones
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                totalOne++;
            }
        }

        int one = 0;        // Running count of ones in the left substring
        int zero = 0;       // Running count of zeros in the left substring
        int ans = INT_MIN;  // Initialize the maximum score to a very low value

        // Iterate through the string to calculate the score for each split
        for (int i = 0; i < n - 1; i++) { // Stop at n - 1 to ensure both parts are non-empty
            if (s[i] == '0') {
                zero++; // Increment zero count for the left substring
            }
            if (s[i] == '1') {
                one++; // Increment one count for the left substring
            }

            // Calculate the score for the current split
            ans = max(ans, zero + totalOne - one);
        }

        return ans; // Return the maximum score
    }
};

/*
Approach:
1. Traverse the string once while maintaining counts of zeros and ones for the left substring.
2. Calculate a partial score (`zero - one`) during the traversal to maximize the contribution of zeros in the left part.
3. Add the remaining ones at the end to the final score to account for the right substring.
4. Return the maximum score found.

Intuition:
Instead of recalculating the total contribution of ones for each split, use a running difference of zeros and ones (`zero - one`) in the left part. This difference indirectly maximizes the score. At the end, add the total remaining ones to get the final result.

Time Complexity:
- A single traversal of the string: \(O(N)\), where \(N\) is the length of the string.

Space Complexity:
- Only integer variables are used, resulting in \(O(1)\) additional space.

*/

class Solution {
public:
    int maxScore(string s) {
        int n = s.length(); // Length of the string
        int res = INT_MIN;  // Initialize the maximum score to a very low value
        int zero = 0, one = 0; // Counters for zeros and ones in the left part

        // Traverse the string to calculate partial scores
        for (int i = 0; i < n - 1; i++) { // Stop at n - 1 to ensure both parts are non-empty
            if (s[i] == '0') {
                zero++; // Increment zero count for the left substring
            } else {
                one++; // Increment one count for the left substring
            }

            // Update the maximum score using the difference (zero - one)
            res = max(res, zero - one);
        }

        // If the last character is '1', increment the count of ones
        if (s[n - 1] == '1') {
            one++;
        }

        // Add the total number of ones to the maximum partial score
        return res + one;
    }
};