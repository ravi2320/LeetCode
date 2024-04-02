/*
12. Integer to Roman
Solved
Medium
Topics
Companies
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999
*/

// Intuition:
// We have two arrays: one containing Roman numeral symbols and the other containing their corresponding integer values.
// We iterate through the value array, starting from the largest value to the smallest.
// At each step, we check how many times the current value fits into the given number.
// We append the corresponding symbol to the result string that many times.
// We then update the given number by taking its remainder when divided by the current value.
// We continue this process until we've processed all values in the array or the given number becomes zero.

// Time Complexity: O(1) since the input integer `num` is bounded by a constant range (1 <= num <= 3999), and the number of symbols used in Roman numerals (13) is also constant.
// Space Complexity: O(1) since the space used by the arrays `symbol` and `value` is constant and independent of the input size.
class Solution {
public:
    // Function to convert an integer to its Roman numeral representation
    string intToRoman(int num) {
        // Arrays containing Roman numeral symbols and their corresponding integer values
        vector<string> symbol{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> value{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        // Initialize an empty string to store the Roman numeral representation
        string ans = "";

        // Iterate through the value array
        for(int i = 0; i < 13; i++){

            // Break the loop if the given number becomes zero
            if(num == 0)
                break;

            // Calculate how many times the current value fits into the given number
            int times = num / value[i];

            // Append the corresponding symbol to the result string that many times
            while(times--){
                ans += symbol[i];
            }

            // Update the given number by taking its remainder when divided by the current value
            num = num % value[i];
        }

        // Return the Roman numeral representation
        return ans;
    }
};