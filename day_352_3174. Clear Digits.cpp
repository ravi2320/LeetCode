/*
3174. Clear Digits
Solved
Easy
Topics
Companies
Hint
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

 

Example 1:

Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.

Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".

 

Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.
*/

//Brute Force
class Solution {
public:
    string clearDigits(string s) {
        
        int i = 0;

        while(i < s.length()){
            if(isdigit(s[i])){
                s.erase(i, 1);
                if(i >= 0){
                    s.erase(i-1, 1);
                }
                i--;
            }
            else{
                i++;
            }
        }

        return s;
    }
};

/*
Approach:
1. Use a **stack** to efficiently remove characters in O(1) instead of O(N) for string `erase()`.
2. Traverse the string and **process each character**:
   - If it's a **digit**, remove the **previous character** (if any) using the stack.
   - Otherwise, push it onto the stack.
3. Construct the final string from the stack.

Intuition:
- Using `s.erase()` repeatedly makes the solution **O(N²)** in worst case, since `erase()` shifts all characters after it.
- A **stack approach** ensures **O(N) time complexity**, avoiding multiple shifts in the string.

Time Complexity: **O(N)**
- Each character is processed **once**.
  
Space Complexity: **O(N)**
- Stack stores at most `N` characters in the worst case.
*/

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st; // Stack to keep track of non-digit characters

        for (char ch : s) {
            if (isdigit(ch)) {
                if (!st.empty()) {
                    st.pop(); // Remove the last non-digit character
                }
            } else {
                st.push(ch); // Push non-digit characters
            }
        }

        // Construct the resulting string from the stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end()); // Reverse to maintain correct order
        return result;
    }
};

	
/*
Approach:
1. Use a **string as a stack** (`res`):
   - If the character is a **digit**, remove the last character from `res` (if it exists).
   - If the character is **not a digit**, add it to `res`.
2. This approach avoids unnecessary shifts (as in `erase()`), making it more efficient.

Intuition:
- The problem requires **removing the last non-digit character** whenever a digit is encountered.
- A **stack (or string used as a stack)** allows efficient **push and pop operations in O(1)**.

Time Complexity: **O(N)**  
- Each character is processed **once**.

Space Complexity: **O(N)** (in worst case)  
- The result string stores at most `N` characters when no digits are encountered.
*/

class Solution {
public:
    string clearDigits(string s) {
        string res = ""; // String used as a stack

        for (char ch : s) {
            if (isdigit(ch)) {
                if (!res.empty()) {
                    res.pop_back(); // Remove last non-digit character
                }
            } else {
                res.push_back(ch); // Add non-digit character
            }
        }

        return res;
    }
};

/*
Approach:
1. Use **two pointers**:
   - `i` iterates over the **original string**.
   - `j` tracks the position in the **modified string**.
2. If `s[i]` is a **digit**, we decrease `j` to remove the last added character.
3. If `s[i]` is **not a digit**, we **store it at `s[j]` and move `j` forward**.
4. The result is `s.substr(0, j)`, containing only the valid characters.

Intuition:
- When a digit is encountered, it removes the last non-digit character.
- Instead of using a separate string (`res`), we modify `s` **in-place**.
- **`j` acts like a stack pointer**, mimicking `push` and `pop`.

Time Complexity: **O(N)**  
- Each character is processed **once**.

Space Complexity: **O(1)**  
- No extra space is used; modifications happen in `s` itself.
*/

class Solution {
public:
    string clearDigits(string s) {
        int j = 0; // Pointer for modified string

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                j = max(j - 1, 0); // Remove last character if j > 0
            } else {
                s[j++] = s[i]; // Store valid character
            }
        }

        return s.substr(0, j); // Return modified string
    }
};