/*
1323. Maximum 69 Number

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

 

Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
 

Constraints:

1 <= num <= 104
num consists of only 6 and 9 digits.
*/

/*
Approach:
1. Convert the given number into a string for easy digit manipulation.
2. Traverse the string from left to right.
3. Change the first occurrence of '6' to '9' since modifying the leftmost digit yields the maximum number.
4. Convert the modified string back to an integer and return it.

Intuition:
- To maximize the number, we should change the first '6' encountered (most significant digit).
- Changing later digits results in smaller increments compared to changing an earlier digit.

Time Complexity: O(d), where d is the number of digits in the number (at most 5 since num ≤ 10^4).
Space Complexity: O(d), for storing the string representation of the number.
*/

class Solution {
public:
    int maximum69Number (int num) {
        // Convert number to string for digit manipulation
        string str = to_string(num);

        // Change the first '6' to '9' to maximize the number
        for(char &x : str){
            if(x == '6'){
                x = '9';
                break; // Only change the first '6'
            }
        }

        // Convert back to integer and return
        return stoi(str);
    }
};
