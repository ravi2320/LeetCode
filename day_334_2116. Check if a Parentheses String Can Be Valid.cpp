/*
2116. Check if a Parentheses String Can Be Valid
Solved
Medium
Topics
Companies
Hint
A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

If locked[i] is '1', you cannot change s[i].
But if locked[i] is '0', you can change s[i] to either '(' or ')'.
Return true if you can make s a valid parentheses string. Otherwise, return false.

 

Example 1:


Input: s = "))()))", locked = "010100"
Output: true
Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.
Example 2:

Input: s = "()()", locked = "0000"
Output: true
Explanation: We do not need to make any changes because s is already valid.
Example 3:

Input: s = ")", locked = "0"
Output: false
Explanation: locked permits us to change s[0]. 
Changing s[0] to either '(' or ')' will not make s valid.
 

Constraints:

n == s.length == locked.length
1 <= n <= 105
s[i] is either '(' or ')'.
locked[i] is either '0' or '1'.
*/

/*
Approach:
1. Use two stacks:
   - `openSt` to store indices of locked '(' parentheses.
   - `openCloseSt` to store indices of unlocked positions ('0').
2. Traverse the string:
   - For unlocked positions ('0'), push their indices onto `openCloseSt`.
   - For locked '(' parentheses, push their indices onto `openSt`.
   - For locked ')' parentheses:
     - Try to balance using `openSt` first, and if that's empty, use `openCloseSt`.
     - If neither is available, the string cannot be valid, so return false.
3. After the traversal, check the remaining `openSt`:
   - Use `openCloseSt` to convert unlocked positions to '(' or ')' as needed.
   - Ensure that all remaining locked '(' can be balanced by unlocked positions.
4. If all conditions are met, return true.

Intuition:
- Locked parentheses must follow strict rules for balancing.
- Unlocked positions can act as wildcards, providing flexibility to balance the string.

Time Complexity:
- \(O(n)\): Single traversal of the string, and at most \(O(n)\) operations for stack management.
  
Space Complexity:
- \(O(n)\): Space for two stacks.

Edge Cases:
1. Odd-length strings are invalid.
2. Fully locked invalid strings return false.
3. Unlocked positions allow flexibility but must still meet balance constraints.

*/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        // If the string length is odd, it cannot be balanced
        if (n % 2 == 1) {
            return false;
        }

        // Stacks for tracking locked '(' and unlocked positions
        stack<int> openSt, openCloseSt;

        // Traverse the string
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                // Unlocked position
                openCloseSt.push(i);
            } else {
                if (s[i] == '(') {
                    // Locked '('
                    openSt.push(i);
                } else {
                    // Locked ')'
                    if (!openSt.empty()) {
                        openSt.pop(); // Match with locked '('
                    } else if (!openCloseSt.empty()) {
                        openCloseSt.pop(); // Use an unlocked position
                    } else {
                        return false; // Unmatched ')'
                    }
                }
            }
        }

        // Match remaining locked '(' with unlocked positions
        while (!openSt.empty() && !openCloseSt.empty() &&
               openSt.top() < openCloseSt.top()) {
            openSt.pop();
            openCloseSt.pop();
        }

        // If all locked '(' are balanced, the string is valid
        return openSt.empty();
    }
};

/*
Approach:
1. The problem requires checking if a string of parentheses `s` can be balanced after modifying unlocked positions.
2. Two passes are performed:
   - **Left-to-right**:
     - Ensure that the number of closing parentheses does not exceed the number of opening parentheses (or unlocked positions that can become opening).
   - **Right-to-left**:
     - Ensure that the number of opening parentheses does not exceed the number of closing parentheses (or unlocked positions that can become closing).
3. If both passes validate the string, it is possible to balance it.

Intuition:
- An even-length string is a prerequisite for balancing parentheses.
- To balance parentheses:
  - The number of open parentheses must not be fewer than the number of close parentheses at any point in the string.
  - Similarly, when traversing from right to left, the reverse condition must hold.

Time Complexity:
- \(O(n)\): Each character in the string is processed twice (once in each pass).

Space Complexity:
- \(O(1)\): No additional space is used apart from a few variables.

Edge Cases:
1. Strings with odd lengths cannot be balanced.
2. Strings with all locked positions and imbalance cannot be fixed.
3. Fully unlocked strings can always be balanced if their length is even.

*/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        
        // If the length is odd, it cannot be a valid parentheses sequence
        if (n % 2 == 1) return false;

        // Pass 1: Left-to-right to validate opening balance
        int open = 0, close = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || locked[i] == '0') {
                open++;  // Count opening parentheses or unlocked positions
            } else {
                close++; // Count closing parentheses
            }
            
            // If closing parentheses exceed possible openings, return false
            if (close > open) return false;
        }

        // Pass 2: Right-to-left to validate closing balance
        open = 0, close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') {
                close++;  // Count closing parentheses or unlocked positions
            } else {
                open++;   // Count opening parentheses
            }
            
            // If opening parentheses exceed possible closings, return false
            if (open > close) return false;
        }

        // If both passes succeed, the string can be balanced
        return true;
    }
};