/*
1137. N-th Tribonacci Number
Solved
Easy
Topics
Companies
Hint
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 

Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/

// Intuition:
// This class provides a solution to find the nth Tribonacci number.
// It uses an iterative approach similar to Fibonacci, where each Tribonacci number is the sum of the previous three numbers.
// The algorithm iterates from the 4th number to the nth number, updating the values of the three previous numbers in each iteration.

// Time Complexity: O(n)
// - 'n' is the input integer.
// - The algorithm iterates from 4 to 'n' once, calculating Tribonacci numbers.
// - Each Tribonacci number is calculated in constant time.

// Space Complexity: O(1)
// - The algorithm uses only a constant amount of extra space for variables.

class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1, ans = 0;

        // Base cases
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;

        // Calculate Tribonacci numbers iteratively
        for (int i = 3; i <= n; i++) {
            ans = a + b + c;
            a = b;
            b = c;
            c = ans;
        }

        return ans; // Return the nth Tribonacci number
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    int n = 5;
    std::cout << "Tribonacci number at index " << n << ": " << obj.tribonacci(n) << std::endl; // Output: 5
    return 0;
}
