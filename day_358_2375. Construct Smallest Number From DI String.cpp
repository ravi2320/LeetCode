/*
2375. Construct Smallest Number From DI String
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.

 

Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.
 

Constraints:

1 <= pattern.length <= 8
pattern consists of only the letters 'I' and 'D'.
*/

class Solution {
public:
    /**
     * Approach:
     * - Generate the smallest permutation of digits from `1` to `n+1`.
     * - Use **next_permutation** to find the lexicographically smallest valid sequence.
     * - Check each permutation against the pattern using a helper function.
     *
     * Intuition:
     * - Since the smallest possible number should be formed, we start with `123...` sequence.
     * - We use **next_permutation** to find the next valid permutation in lexicographic order.
     * - The `matches` function ensures that the generated sequence satisfies the given pattern.
     *
     * Time Complexity:
     * - Worst case: **O(N! * N)** (`O(N!)` for permutations and `O(N)` for checking each pattern).
     * - This is inefficient for large `N`, and an optimal **greedy stack-based approach** is recommended.
     *
     * Space Complexity:
     * - **O(N)** for storing the number sequence.
     */

    bool matches(string &num, string &pattern) {
        for (int i = 0; i < pattern.size(); i++) {
            if ((pattern[i] == 'I' && num[i] > num[i + 1]) ||
                (pattern[i] == 'D' && num[i] < num[i + 1])) {
                return false;
            }
        }
        return true;
    }

    string smallestNumber(string pattern) {
        string num = "";
        int n = pattern.size();

        // Create the initial smallest number sequence: "123...(n+1)"
        for (int i = 1; i <= n + 1; i++) {
            num.push_back(i + '0');
        }

        // Find the lexicographically smallest permutation that matches the pattern
        while (!matches(num, pattern)) {
            next_permutation(num.begin(), num.end());
        }

        return num;
    }
};

class Solution {
public:
    /**
     * Approach:
     * - Use a **stack-based greedy approach** to generate the smallest lexicographical number.
     * - Push numbers onto the stack while encountering `'D'`.
     * - If an `'I'` is encountered or we reach the end, pop all elements from the stack.
     *
     * Intuition:
     * - To construct the smallest number, we should delay placing larger numbers when encountering `'D'` patterns.
     * - Using a stack helps maintain the correct decreasing order for contiguous `'D'` sequences.
     * - Once an `'I'` appears, we flush the stack, ensuring minimal numbers are placed earlier.
     *
     * Time Complexity:
     * - **O(N)**: Each number is pushed and popped from the stack exactly once.
     *
     * Space Complexity:
     * - **O(N)**: The stack stores at most `N+1` elements.
     */

    string smallestNumber(string pattern) {
        int n = pattern.size();
        string num = "";
        stack<char> st;
        int cnt = 1;

        for (int i = 0; i <= n; i++) {
            st.push(cnt + '0');  // Push the next number onto the stack
            cnt++;

            // If an 'I' is encountered or it's the last number, pop stack
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    num.push_back(st.top());
                    st.pop();
                }
            }
        }

        return num;
    }
};