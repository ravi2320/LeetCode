/*
1432. Max Difference You Can Get From Changing an Integer

Solved
Medium
Topics
Companies
Hint
You are given an integer num. You will apply the following steps to num two separate times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). Note y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
Let a and b be the two results from applying the operation to num independently.

Return the max difference between a and b.

Note that neither a nor b may have any leading zeros, and must not be 0.


Example 1:

Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888
Example 2:

Input: num = 9
Output: 8
Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8
 

Constraints:

1 <= num <= 108
*/

/*
Approach:
We are given a number and we want to maximize and minimize it by replacing a digit with another digit,
such that only one type of digit is replaced (all its occurrences), and then return the difference
between the maximum and minimum values.

To form:
- Maximum: Replace the **first digit that is not '9'** with '9'.
- Minimum:
    - If the first digit is not '1', replace all occurrences of it with '1'.
    - Otherwise, search from second digit onwards for the first digit that is neither '0' nor '1' and replace all of it with '0'.

Intuition:
To **maximize**, we increase digits as much as possible (towards '9').
To **minimize**, we reduce digits, starting from the most significant ones,
but the first digit shouldn't be zero (to avoid invalid number), hence we use '1' instead of '0' for it.

Time Complexity: O(n)
Where `n` is the number of digits in the number. We loop over the digits a constant number of times.

Space Complexity: O(1)
Only strings and basic variables are used; no extra space proportional to input size.
*/

class Solution {
public:
    // Replace all occurrences of `rep` with `digit` in string `num`
    string replaceWithDigit(string num, char digit, char rep) {
        int n = num.length();
        for (int i = 0; i < n; i++) {
            if (num[i] == rep) {
                num[i] = digit;
            }
        }
        return num;
    }

    int maxDiff(int num) {
        string num_str = to_string(num);  // Convert number to string
        int n = num_str.length();

        // Generate maximum value by replacing first non-9 digit with 9
        string max_str = num_str;
        for (int i = 0; i < n; i++) {
            if (num_str[i] != '9') {
                max_str = replaceWithDigit(num_str, '9', num_str[i]);
                break;
            }
        }

        // Generate minimum value
        string min_str = num_str;
        if (num_str[0] != '1') {
            // Replace the first digit (if not '1') with '1'
            min_str = replaceWithDigit(num_str, '1', num_str[0]);
        } else {
            // Replace first digit (from index 1 onward) that is not '0' or '1' with '0'
            for (int i = 1; i < n; i++) {
                if (num_str[i] != '0' && num_str[i] != '1') {
                    min_str = replaceWithDigit(num_str, '0', num_str[i]);
                    break;
                }
            }
        }

        // Return the difference between max and min values
        return stoi(max_str) - stoi(min_str);
    }
};
