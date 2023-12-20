/*

204. Count Primes
Solved
Medium
Topics
Companies
Hint
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106

*/

#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Step 1: Initialize a vector to track prime numbers up to 'n'
        std::vector<bool> isPrime(n, false);

        // Step 2: Mark all odd numbers as potential prime numbers
        for (int i = 3; i < n; i += 2) {
            isPrime[i] = true;
        }

        // Special case: 2 is a prime number
        isPrime[2] = true;

        // Step 3: Iterate through odd numbers up to the square root of 'n'
        for (int i = 3; i * i < n; i += 2) {
            // Step 4: If i is a prime number, mark its multiples as non-prime
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 5: Count the number of prime numbers
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};
