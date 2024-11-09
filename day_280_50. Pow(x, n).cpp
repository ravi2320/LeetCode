/*
50. Pow(x, n)
Solved
Medium
Topics
Companies
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

/*
Approach:
1. Count the occurrence of each digit in the input array `arr` using a frequency array `digits`.
2. Construct two strings `num1` and `num2` by alternating digits to ensure the numbers are balanced in length.
3. Alternate appending digits to `num1` and `num2` based on their frequency count to minimize their sum.
4. Use the helper function `addNumbers` to add `num1` and `num2` as if they were large numbers, as they may exceed typical integer limits.

Time Complexity: O(d + max(n, m)), where d is the number of digits (10 in our case), and `n` and `m` are the lengths of `num1` and `num2`.
Space Complexity: O(n + m), where `n` and `m` are the lengths of `num1` and `num2`.

*/

class Solution {
public:
    // Function to add two large numbers represented as strings
    string addNumbers(string num1, string num2) {
        int n = num1.length() - 1, m = num2.length() - 1;
        string result = "";
        int carry = 0;

        // Process both numbers from the end towards the start
        while (n >= 0 || m >= 0 || carry) {
            int n1 = (n >= 0) ? (num1[n--] - '0') : 0;
            int n2 = (m >= 0) ? (num2[m--] - '0') : 0;

            int sum = n1 + n2 + carry;
            result += (sum % 10) + '0';
            carry = sum / 10;
        }

        // Since we added digits from the least significant side, reverse the result
        reverse(result.begin(), result.end());
        return result;
    }

    // Function to split digits into two numbers and return their minimum sum
    string minSum(vector<int> &arr) {
        vector<int> digits(10, 0);
        
        // Count each digit's occurrence
        for (int &x : arr) {
            digits[x]++;
        }

        // Form two numbers by distributing digits to get the smallest sum
        string num1 = "", num2 = "";
        bool flag = true; // Use flag to alternate adding digits to num1 and num2

        for (int i = 1; i <= 9; i++) {
            while (digits[i] > 0) {
                if (flag) {
                    num1 += to_string(i);
                } else {
                    num2 += to_string(i);
                }
                flag = !flag;
                digits[i]--;
            }
        }

        // Return the sum of the two strings
        return addNumbers(num1, num2);
    }
};
