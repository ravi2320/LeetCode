/*
264. Ugly Number II
Solved
Medium
Topics
Companies
Hint
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690
*/

/*
Intuition:
- The problem is to find the nth ugly number, where an ugly number is defined as a number that can be written as a product of only the prime numbers 2, 3, and 5.
- We can use dynamic programming to generate ugly numbers in order.
- Start with the first ugly number, which is 1. Then, generate subsequent ugly numbers by multiplying the previous ugly numbers by 2, 3, and 5, and picking the smallest result that hasn't been used yet.
- Maintain three pointers (i2, i3, i5) for each multiplier (2, 3, 5) to ensure that every possible ugly number is generated in ascending order.

Time Complexity:
- The time complexity is O(n), where `n` is the number of ugly numbers we need to generate. This is because we are generating each ugly number in sequence.

Space Complexity:
- The space complexity is O(n) since we store the first `n` ugly numbers in the array `arr`.

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        // Pointers for multiples of 2, 3, and 5.
        int i2 = 1, i3 = 1, i5 = 1;

        // Vector to store the first n ugly numbers.
        vector<int> arr(n + 1);

        // The first ugly number is 1.
        arr[1] = 1;

        // Generate the next ugly numbers.
        for (int i = 2; i <= n; i++) {
            // Compute the next multiples of 2, 3, and 5.
            int i2Ugly = arr[i2] * 2;
            int i3Ugly = arr[i3] * 3;
            int i5Ugly = arr[i5] * 5;

            // Select the smallest ugly number among them.
            arr[i] = min(i2Ugly, min(i3Ugly, i5Ugly));

            // Increment the pointers when the corresponding ugly number is used.
            if (arr[i] == i2Ugly) i2++;
            if (arr[i] == i3Ugly) i3++;
            if (arr[i] == i5Ugly) i5++;
        }

        // Return the nth ugly number.
        return arr[n];
    }
};
