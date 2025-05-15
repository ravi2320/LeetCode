/*
3337. Total Characters in String After Transformations II
Solved
Hard
Topics
Companies
Hint
You are given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:

Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".
The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3 consecutive characters ahead of it, which results in "zab".
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: s = "abcyy", t = 2, nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]

Output: 7

Explanation:

First Transformation (t = 1):

'a' becomes 'b' as nums[0] == 1
'b' becomes 'c' as nums[1] == 1
'c' becomes 'd' as nums[2] == 1
'y' becomes 'z' as nums[24] == 1
'y' becomes 'z' as nums[24] == 1
String after the first transformation: "bcdzz"
Second Transformation (t = 2):

'b' becomes 'c' as nums[1] == 1
'c' becomes 'd' as nums[2] == 1
'd' becomes 'e' as nums[3] == 1
'z' becomes 'ab' as nums[25] == 2
'z' becomes 'ab' as nums[25] == 2
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.

Example 2:

Input: s = "azbk", t = 1, nums = [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]

Output: 8

Explanation:

First Transformation (t = 1):

'a' becomes 'bc' as nums[0] == 2
'z' becomes 'ab' as nums[25] == 2
'b' becomes 'cd' as nums[1] == 2
'k' becomes 'lm' as nums[10] == 2
String after the first transformation: "bcabcdlm"
Final Length of the string: The string is "bcabcdlm", which has 8 characters.

 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 109
nums.length == 26
1 <= nums[i] <= 25
*/

/*
Approach:
- Each character in the string can be "transformed" based on the allowed shifts specified in `nums`.
- For each character from 'a' to 'z' (i.e., 0 to 25), we build a transformation matrix T such that:
    T[new_char][old_char] = number of ways old_char can be transformed into new_char.
- We raise this transformation matrix T to the power of `t` using fast matrix exponentiation.
- Then we apply this transformation to the frequency vector of the input string.

Intuition:
- Each transformation step is essentially applying the matrix T on the current state of letter frequencies.
- After `t` transformations, the net effect is `T^t`.
- Multiply T^t with the frequency vector to get the final frequencies.
- The final result is the sum of these frequencies.

Time Complexity:
- Matrix Multiplication: O(26^3)
- Matrix Exponentiation: O(log t * 26^3)
- Final Frequency Update: O(26^2)
=> Overall: **O(26^3 * log t)** ≈ Constant time due to small size.

Space Complexity:
- O(26^2) for storing matrices.

*/

class Solution {
    int M = 1e9 + 7; // Modulo value for large number handling

public:
    // Matrix multiplication (modulo M)
    vector<vector<int>> matrixMul(vector<vector<int>> &A, vector<vector<int>> &B) {
        vector<vector<int>> C(26, vector<int>(26, 0));

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % M) % M;
                }
            }
        }

        return C;
    }

    // Fast matrix exponentiation
    vector<vector<int>> matrixExponention(vector<vector<int>> &base, int exp) {
        // Base: identity matrix
        vector<vector<int>> res(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) res[i][i] = 1;

        while (exp > 0) {
            if (exp % 2 == 1) {
                res = matrixMul(res, base);
            }
            base = matrixMul(base, base);
            exp /= 2;
        }

        return res;
    }

    // Main function
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> freq(26, 0);

        // Count initial character frequencies
        for (char &x : s) {
            freq[x - 'a']++;
        }

        // Build transformation matrix T based on nums
        vector<vector<int>> T(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int add = 1; add <= nums[i]; add++) {
                T[(i + add) % 26][i]++;
            }
        }

        // Raise transformation matrix to power t
        vector<vector<int>> T_exp = matrixExponention(T, t);

        // Apply T^t on initial frequency vector
        vector<int> updatedFreq(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                updatedFreq[i] = (updatedFreq[i] + 1LL * T_exp[i][j] * freq[j] % M) % M;
            }
        }

        // Final result: sum of updated frequencies
        int resLen = 0;
        for (int i = 0; i < 26; i++) {
            resLen = (resLen + updatedFreq[i]) % M;
        }

        return resLen;
    }
};
