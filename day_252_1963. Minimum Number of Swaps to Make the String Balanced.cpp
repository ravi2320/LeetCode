/*
1963. Minimum Number of Swaps to Make the String Balanced
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

 

Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
 

Constraints:

n == s.length
2 <= n <= 106
n is even.
s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.
*/

/*
Approach:
1. **Balancing the brackets**:
   - We iterate through the string and count the number of unbalanced open brackets (`[`). 
   - Every time we encounter a closing bracket (`]`) while we have unbalanced open brackets (`[`), we reduce the count of unbalanced open brackets.
   - After the iteration, the remaining unbalanced open brackets can only be balanced by swapping them with the same number of unbalanced closing brackets.
   
2. **Minimum swaps**:
   - Each swap fixes two unbalanced brackets (one open and one close), so to balance the remaining unbalanced open brackets, the number of swaps required is `(open + 1) / 2`. This formula comes from the fact that we can match two unbalanced brackets with one swap.

3. **Time Complexity**:
   - **O(n)**: We traverse the string once to count the unbalanced brackets.

4. **Space Complexity**:
   - **O(1)**: Only a few variables are used, so the space complexity is constant.

*/

class Solution {
public:
    int minSwaps(string s) {
        int open = 0;  // To track unbalanced open brackets '['
        
        // Traverse through the string to calculate unbalanced brackets
        for(char &x : s){
            if(x == '[') {
                open++;  // Increment when an open bracket is found
            }
            else if(x == ']' && open > 0) {
                open--;  // Decrement when a closing bracket can balance an open one
            }
        }

        // Return the minimum number of swaps needed to balance the string
        return (open + 1) / 2;  // This gives the number of swaps required
    }
};
