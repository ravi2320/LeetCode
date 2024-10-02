/*
1922. Count Good Numbers
Solved
Medium
Topics
Companies
Hint
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015
*/

/*
Approach:
- This problem involves calculating the number of "good" digit sequences of length `n` where the digits alternate between even digits and prime digits.
- For even positions (0, 2, 4, ...), there are 5 possible digits (0, 2, 4, 6, 8).
- For odd positions (1, 3, 5, ...), there are 4 possible prime digits (2, 3, 5, 7).
- We compute the number of even and odd positions based on `n`, and then raise 5 to the power of the number of even positions, and 4 to the power of the number of odd positions.
- Using modular exponentiation to efficiently calculate large powers under a modulo, we return the result of multiplying these two results.

Time Complexity:
- O(log n) for each modular exponentiation (since the function calls `powMod` for both `5^even` and `4^odd`).
- Overall time complexity is O(log n).

Space Complexity:
- O(log n) due to the recursive depth of the `powMod` function.
*/

class Solution {
public:
    int MOD = 1e9+7;  // The modulo value to prevent overflow
    
    // Helper function to compute x^n % MOD using recursion (modular exponentiation)
    long long powMod(long long x, long long n) {
        if(n == 0) return 1;  // Base case: any number to the power of 0 is 1

        // Recursively calculate the power for n/2
        long long temp = powMod(x, n / 2);
        temp = (temp * temp) % MOD;  // Square the result and apply modulo

        // If n is odd, multiply by x once more and apply modulo
        if(n % 2 == 0) {
            return temp;  // Return the result for an even exponent
        } else {
            return (x * temp) % MOD;  // Return x * result for an odd exponent
        }
    }

    // Main function to count the number of good numbers of length n
    int countGoodNumbers(long long n) {
        // Number of even positions is (n+1)/2, number of odd positions is n/2
        long long even = (n + 1) / 2;  
        long long odd = n / 2;  

        // Calculate 5^even % MOD for even positions and 4^odd % MOD for odd positions
        long long first = powMod(5, even);  
        long long second = powMod(4, odd);  

        // Multiply both results and return the final result mod MOD
        return (int)((first * second) % MOD);  
    }
};
