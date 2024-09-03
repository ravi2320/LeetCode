/*
1945. Sum of Digits of String After Convert
Solved
Easy
Topics
Companies
Hint
You are given a string s consisting of lowercase English letters, and an integer k.

First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.

 

Example 1:

Input: s = "iiii", k = 1
Output: 36
Explanation: The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.
Example 2:

Input: s = "leetcode", k = 2
Output: 6
Explanation: The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.
Example 3:

Input: s = "zbax", k = 2
Output: 8
 

Constraints:

1 <= s.length <= 100
1 <= k <= 10
s consists of lowercase English letters.
*/

/*
**Problem Statement:**
- You are given a string `s` consisting of lowercase English letters, and an integer `k`. Each letter is converted into its position in the alphabet (e.g., 'a' -> 1, 'b' -> 2, ... 'z' -> 26).
- The resulting numbers are then summed. The process is repeated `k` times, where in each step the digits of the sum from the previous step are summed again to form a new sum.
- The goal is to find the resulting sum after `k` transformations.

**Approach:**
1. **Initial Conversion:**
   - Convert each character in the string to its corresponding position in the alphabet.
   - Sum the digits of these positions.

2. **Digit Sum Transformation:**
   - Apply the digit sum operation on the resulting sum. This operation is repeated `k` times or until the sum becomes a single digit.

3. **Edge Cases:**
   - If `k` is 1, the process is straightforward: sum the digits only once.
   - If the initial sum is already a single digit, additional transformations are unnecessary.

**Time Complexity:**
- The time complexity is `O(n + k*log(sum))`, where `n` is the length of the string and `log(sum)` represents the number of digits in the sum, which is the cost of each digit sum transformation.

**Space Complexity:**
- The space complexity is `O(1)` since we are only using a few integer variables to store the sums.

**Example Usage:**
- Given `s = "iiii"`, `k = 1`, the function will return `36` as the initial sum, and `9` after one transformation.

*/

class Solution {
public:
    // Function to calculate the digit sum of a given number
    int digitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int getLucky(string s, int k) {
        int sum = 0;

        // Convert each character to its corresponding position in the alphabet and sum them
        for(char &x : s){
            int val = x - 'a' + 1;
            if(val >= 10){
                sum += val / 10 + val % 10;  // Sum the digits if the value is two digits
            }
            else{
                sum += val;  // Directly add if the value is a single digit
            }
        }

        k--;  // We have already done one transformation

        // Perform k-1 additional transformations
        while(k-- && sum >= 10){
            sum = digitSum(sum);
        }

        return sum;  // Return the final sum after k transformations
    }
};

// Example usage:
int main() {
    Solution sol;
    string s = "iiii";
    int k = 1;
    int result = sol.getLucky(s, k);
    cout << "The resulting sum after " << k << " transformations is: " << result << endl;
    return 0;
}
