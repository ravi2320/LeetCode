/*
678. Valid Parenthesis String
Solved
Medium
Topics
Companies
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/

/*
Intuition:
- We can use dynamic programming to solve this problem efficiently.
- We define a recursive function `solve` that checks whether the string `s` is a valid string starting from index `idx` with `open` number of open parentheses.
- The base case of the recursion is when we reach the end of the string (`idx == n`), in which case the string is valid if and only if there are no remaining open parentheses (`open == 0`).
- We use memoization to avoid redundant calculations by storing the result of each subproblem in the `dp` array.
- At each index `idx`, we have three choices:
    1. If `s[idx]` is '(', we increment the count of open parentheses (`open`) and move to the next index.
    2. If `s[idx]` is '*', we have three options:
        - Increment `open` and move to the next index.
        - Keep `open` unchanged and move to the next index.
        - Decrement `open` if `open > 0` and move to the next index.
    3. If `s[idx]` is ')', we decrement the count of open parentheses (`open`) if `open > 0` and move to the next index.

Time Complexity: O(n^2), where n is the length of the string.
- We have two nested loops in the `solve` function, which results in O(n^2) time complexity.
- However, due to memoization, the actual time complexity is significantly reduced.

Space Complexity: O(n^2).
- We use a 2D DP array of size 101x101 to store the results of subproblems.
- Additionally, we use recursion, which results in a maximum recursion depth of O(n).
- Therefore, the overall space complexity is O(n^2).
*/

class Solution {
public:
    int dp[101][101];
    
    // Recursive function to check if the string is valid starting from index `idx` with `open` number of open parentheses
    bool solve(int open, int idx, string &s, int n) {
        // Base case: If we reach the end of the string
        if (idx == n) {
            return open == 0; // The string is valid if there are no remaining open parentheses
        }

        // Check if the result is already calculated
        if (dp[idx][open] != -1)
            return dp[idx][open];

        bool isValid = false;
        
        // If the current character is '('
        if (s[idx] == '(') {
            isValid = solve(open + 1, idx + 1, s, n); // Increment the count of open parentheses and move to the next index
        }
        // If the current character is '*'
        else if (s[idx] == '*') {
            isValid |= solve(open + 1, idx + 1, s, n); // Option 1: Increment open and move to the next index
            isValid |= solve(open, idx + 1, s, n); // Option 2: Keep open unchanged and move to the next index
            if (open > 0)
                isValid |= solve(open - 1, idx + 1, s, n); // Option 3: Decrement open if open > 0 and move to the next index
        }
        // If the current character is ')'
        else if (open > 0) {
            isValid |= solve(open - 1, idx + 1, s, n); // Decrement the count of open parentheses if open > 0 and move to the next index
        }

        // Store the result in the DP array
        return dp[idx][open] = isValid;
    }
    
    // Main function to check if the string is a valid string
    bool checkValidString(string s) {
        int n = s.length(); // Length of the string
        memset(dp, -1, sizeof(dp)); // Initialize DP array with -1
        return solve(0, 0, s, n); // Start from index 0 with 0 open parentheses
    }
};


/*
Intuition:
- We can use dynamic programming to solve this problem efficiently.
- We define a 2D DP array `dp` where dp[i][j] represents whether the substring starting from index i with j open parentheses is valid.
- We initialize the DP array with size (n+1)x(n+1) and fill it with false.
- We set the base case when the string is empty (i.e., dp[n][0] = true).
- We iterate over the string from right to left and over possible counts of open parentheses.
- At each position, we consider three options:
    1. If the current character is '*', we have three options:
        - Option 1: Increment open and move to the next index.
        - Option 2: Keep open unchanged and move to the next index.
        - Option 3: Decrement open if open > 0 and move to the next index.
    2. If the current character is '(', we increment open and move to the next index.
    3. If the current character is ')', we decrement open if open > 0 and move to the next index.
- We update the DP array with the result of each subproblem.
- Finally, we return the result for the first index of the DP array, which represents the entire string with 0 open parentheses.

Time Complexity: O(n^2), where n is the length of the string.
- We have two nested loops iterating over the string and the count of open parentheses, resulting in O(n^2) time complexity.

Space Complexity: O(n^2).
- We use a 2D DP array of size (n+1)x(n+1) to store the results of subproblems.
- Therefore, the overall space complexity is O(n^2).
*/

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length(); // Length of the string
        
        // Initialize DP array with size (n+1)x(n+1) and fill with false
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        
        // Base case: When the string is empty, it is valid if there are no open parentheses
        dp[n][0] = true;
        
        // Iterate over the string from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Iterate over possible counts of open parentheses
            for (int open = 0; open <= n; open++) {
                bool isValid = false;
                
                // If the current character is '*'
                if (s[i] == '*') {
                    // Option 1: Increment open and move to the next index
                    if (open < n)
                        isValid |= dp[i + 1][open + 1];
                    // Option 2: Keep open unchanged and move to the next index
                    isValid |= dp[i + 1][open];
                    // Option 3: Decrement open if open > 0 and move to the next index
                    if (open > 0)
                        isValid |= dp[i + 1][open - 1];
                }
                // If the current character is '('
                else if (s[i] == '(') {
                    // Increment open and move to the next index
                    isValid |= dp[i + 1][open + 1];
                }
                // If the current character is ')'
                else if (open > 0) {
                    // Decrement open if open > 0 and move to the next index
                    isValid |= dp[i + 1][open - 1];
                }

                // Store the result in the DP array
                dp[i][open] = isValid;
            }
        }
        // Return the result for the first index (0 open parentheses)
        return dp[0][0];
    }
};


/*
Intuition:
- We use two stacks to keep track of the indices of open parentheses '(' and asterisks '*'.
- We iterate over the string and process each character:
    - If the current character is '(', we push its index onto the openBracket stack.
    - If the current character is '*', we push its index onto the asterisk stack.
    - If the current character is ')', we check if there is a matching open bracket '(' or an asterisk '*':
        - If there is a matching open bracket, we pop it from the openBracket stack.
        - If there is no matching open bracket but there is an asterisk, we pop it from the asterisk stack.
        - If there is neither a matching open bracket nor an asterisk, the string is invalid.
- After processing all characters, we need to ensure that each open bracket '(' has a matching asterisk '*' or is closed by another ')' bracket:
    - We iterate over the remaining elements in both stacks and compare their indices.
    - If the index of an open bracket is greater than the index of an asterisk, the string is invalid.
- If all open brackets have matching asterisks or are closed by ')' brackets, the string is valid.

Time Complexity: O(n), where n is the length of the string.
- We iterate over the string once to process each character.

Space Complexity: O(n).
- We use two stacks to store indices, which can have at most n elements.
*/

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openBracket; // Stack to store indices of open parentheses '('
        stack<int> asterisk; // Stack to store indices of asterisks '*'

        // Iterate over the string and process each character
        for(int i = 0; i < s.length(); i++) {
            // If the current character is '('
            if(s[i] == '(')
                openBracket.push(i);
            // If the current character is '*'
            else if(s[i] == '*')
                asterisk.push(i);
            // If the current character is ')'
            else {
                // Check if there is a matching open bracket '('
                if(!openBracket.empty())
                    openBracket.pop();
                // If there is no matching open bracket but there is an asterisk '*', pop it
                else if(!asterisk.empty())
                    asterisk.pop();
                // If there is neither a matching open bracket nor an asterisk, the string is invalid
                else 
                    return false;
            }
        }

        // Check if each remaining open bracket '(' has a matching asterisk '*' or is closed by ')'
        while(!openBracket.empty() && !asterisk.empty()) {
            // If the index of an open bracket is greater than the index of an asterisk, the string is invalid
            if(openBracket.top() > asterisk.top())
                return false;

            openBracket.pop();
            asterisk.pop();
        }

        // If all open brackets have matching asterisks or are closed by ')', the string is valid
        return openBracket.empty();
    }
};


/*
Intuition:
- We maintain two variables 'open' and 'close' to keep track of the number of open and close brackets.
- We iterate over the string from left to right and update the 'open' count whenever we encounter '(' or '*'.
- If we encounter ')', we decrement the 'open' count. If 'open' becomes negative, it means there are more close brackets than open brackets, which makes the string invalid.
- We repeat the same process while iterating over the string from right to left to handle the '*' characters before the open brackets.
- If both iterations complete without encountering any inconsistencies, the string is valid.

Time Complexity: O(n), where n is the length of the string.
- We iterate over the string twice, once from left to right and once from right to left.

Space Complexity: O(1).
- We use only a constant amount of extra space to store the 'open' and 'close' counts.
*/

class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0;

        // Iterate over the string from left to right
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '*')
                open++;
            else
                open--;

            if(open < 0)
                return false;
        }

        // Iterate over the string from right to left
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == ')' || s[i] == '*')
                close++;
            else
                close--;

            if(close < 0)
                return false;
        }

        return true;
    }
};
