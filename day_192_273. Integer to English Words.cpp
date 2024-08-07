/*
273. Integer to English Words
Solved
Hard
Topics
Companies
Hint
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

0 <= num <= 231 - 1
*/

// Intuition: This function converts a number into its English words representation. 
// It breaks down the number recursively into parts (units, tens, hundreds, thousands, millions, billions),
// and uses pre-defined mappings for numbers less than 10, 20, and 100.

// Time Complexity: O(log N), where N is the input number, since the number of digits determines the depth of recursion.
// Space Complexity: O(log N), due to the recursion stack space.

class Solution {
public:

    // Unordered maps to store words for numbers less than 10, 20, and 100
    unordered_map<int, string> belowTen = { {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"} };
    unordered_map<int, string> belowTwenty = { {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"} };
    unordered_map<int, string> belowHundred = { {1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"} };

    string solve(int num) {
        if (num < 10) {
            return belowTen[num];
        }

        if (num < 20) {
            return belowTwenty[num];
        }

        if (num < 100) { // 89 -> "Eighty Nine"
            return belowHundred[num / 10] + ((num % 10 != 0) ? " " + belowTen[num % 10] : "");
        }

        if (num < 1000) { // 879 -> "Eight Hundred Seventy Nine"
            return solve(num / 100) + " Hundred" + ((num % 100 != 0) ? " " + solve(num % 100) : "");
        }

        if (num < 1000000) { // 123456 -> "One Hundred Twenty Three Thousand Four Hundred Fifty Six"
            return solve(num / 1000) + " Thousand" + ((num % 1000 != 0) ? " " + solve(num % 1000) : "");
        }

        if (num < 1000000000) { // 123456789 -> "One Hundred Twenty Three Million Four Hundred Fifty Six Thousand Seven Hundred Eighty Nine"
            return solve(num / 1000000) + " Million" + ((num % 1000000 != 0) ? " " + solve(num % 1000000) : "");
        }

        return solve(num / 1000000000) + " Billion" + ((num % 1000000000 != 0) ? " " + solve(num % 1000000000) : "");
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        return solve(num);
    }
};
