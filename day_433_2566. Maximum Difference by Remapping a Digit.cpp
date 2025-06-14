/*
2566. Maximum Difference by Remapping a Digit

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

Notes:

When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
Bob can remap a digit to itself, in which case num does not change.
Bob can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.
 

Example 1:

Input: num = 11891
Output: 99009
Explanation: 
To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.
Example 2:

Input: num = 90
Output: 99
Explanation:
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.
 

Constraints:

1 <= num <= 108
*/

/*
Approach:
We are given an integer `num`. We want to compute the **maximum and minimum numbers**
possible by replacing all occurrences of a single digit with another digit. Then, we
return the **difference between the maximum and minimum** numbers formed this way.

To form:
- Maximum: Replace the **first digit that is not '9'** with '9'.
- Minimum: Replace **all instances of the first digit** with '0'.

We convert the number to a string for easy manipulation, apply the replacement logic,
then convert back to integer and compute the difference.

Intuition:
To maximize, we want to increase digits (replace with '9').
To minimize, we want to decrease digits (replace with '0') starting from the most significant digit.

Time Complexity: O(n)
Where `n` is the number of digits in the input number (up to 10 digits for int).
We scan the string a few times linearly.

Space Complexity: O(1)
Only string variables and primitive data types used.
*/

class Solution {
public:
    // Helper function to replace all occurrences of `rep` in `num` with `digit`
    string replaceWithDigit(string num, char digit, char rep) {
        int n = num.length();

        for (int i = 0; i < n; i++) {
            if (num[i] == rep) {
                num[i] = digit;
            }
        }

        return num;
    }

    int minMaxDifference(int num) {
        string num_str = to_string(num);  // Convert integer to string
        int n = num_str.length();

        string max_str = num_str;

        // Create the maximum number by replacing first non-'9' digit with '9'
        for (int i = 0; i < n; i++) {
            if (num_str[i] != '9') {
                max_str = replaceWithDigit(num_str, '9', num_str[i]);
                break;
            }
        }

        // Create the minimum number by replacing all of the first digit with '0'
        string min_str = replaceWithDigit(num_str, '0', num_str[0]);

        // Convert back to integer
        long long num1 = stoi(max_str);
        long long num2 = stoi(min_str);

        // Return the difference between max and min
        return num1 - num2;
    }
};
