/*
2843. Count Symmetric Integers
Solved
Easy
Topics
Companies
Hint
You are given two positive integers low and high.

An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

Return the number of symmetric integers in the range [low, high].

 

Example 1:

Input: low = 1, high = 100
Output: 9
Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
Example 2:

Input: low = 1200, high = 1230
Output: 4
Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.
 

Constraints:

1 <= low <= high <= 104
*/

/*
Intuition:
----------
A number is said to be symmetric if it has an even number of digits, and the sum of its first half digits
is equal to the sum of its second half digits. We need to count such numbers in the range [low, high].

Approach:
---------
1. Iterate through every number from `low` to `high`.
2. Convert each number to a string to easily access digits.
3. Skip numbers with odd number of digits.
4. Split the number into two halves.
5. Calculate the sum of digits in the first and second halves.
6. If both sums are equal, increment the counter.
7. Return the total count.

Time Complexity:
----------------
O(N * D), where N is the range (high - low + 1) and D is the number of digits per number (at most 6).

Space Complexity:
-----------------
O(1), ignoring the space for string conversion.
*/

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for (int i = low; i <= high; i++) {
            string num = to_string(i);
            int len = num.size();

            // Skip if number of digits is odd
            if (len % 2) continue;

            int leftSum = 0;
            for (int j = 0; j < len / 2; j++) {
                leftSum += num[j] - '0';
            }

            int rightSum = 0;
            for (int j = len / 2; j < len; j++) {
                rightSum += num[j] - '0';
            }

            // If both halves have equal digit sums, count it
            if (leftSum == rightSum) {
                cnt++;
            }
        }

        return cnt;
    }
};


/*
Intuition:
----------
A symmetric integer is one that has an even number of digits and the sum of the first half of the digits 
equals the sum of the second half. For example, 1212 and 1233 are symmetric, but 1223 is not.

Approach:
---------
- We only need to consider 2-digit and 4-digit numbers since they are the only symmetric-length numbers 
  within the range [low, high] that are ≤ 9999.
- For 2-digit numbers:
  - Only numbers divisible by 11 (e.g., 11, 22, 33, ..., 99) will have equal digits and hence are symmetric.
- For 4-digit numbers:
  - Extract digits individually using division and modulo operations.
  - Compare sum of first two digits with the sum of last two digits.
- Count and return all such symmetric numbers.

Time Complexity:
----------------
O(N), where N is the number of integers in the range [low, high].

Space Complexity:
-----------------
O(1), constant space used.
*/

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for(int num = low; num <= high; num++) {
            // Check 2-digit symmetric integers (like 11, 22,...,99)
            if(num >= 10 && num <= 99 && num % 11 == 0) {
                cnt++;
            }
            // Check 4-digit symmetric integers
            else if(num >= 1000 && num <= 9999) {
                int firstDigit = num / 1000;
                int secondDigit = (num / 100) % 10;
                int thirdDigit = (num / 10) % 10;
                int fourthDigit = num % 10;

                if(firstDigit + secondDigit == thirdDigit + fourthDigit) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
