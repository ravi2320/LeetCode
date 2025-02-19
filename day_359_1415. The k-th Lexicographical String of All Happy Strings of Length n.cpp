/*
1415. The k-th Lexicographical String of All Happy Strings of Length n
Solved
Medium
Topics
Companies
Hint
A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
 

Constraints:

1 <= n <= 10
1 <= k <= 100
*/

/**
 * Approach:
 * - We generate **all valid happy strings** of length `n` using **backtracking**.
 * - A happy string is a string where **no two adjacent characters** are the same.
 * - We iterate over `'a'`, `'b'`, and `'c'` and recursively build valid strings.
 * - If we reach the required length, we store the string in the result.
 *
 * Intuition:
 * - We **explore all possible choices** while ensuring the last character is not repeated.
 * - **Backtracking** allows us to efficiently generate all possible happy strings.
 * - Once we have all valid strings, we return the **k-th lexicographically smallest string**.
 *
 * Time Complexity:
 * - **O(3^N)**: At each position, we have at most **3 choices** (excluding the previous character).
 * - This results in an upper bound of `O(3^N)`, but pruning reduces the actual number of calls.
 *
 * Space Complexity:
 * - **O(3^N)**: We store all happy strings in a result vector.
 * - **O(N)**: Additional stack space for recursive calls.
 */

class Solution {
public:
    // Recursive function to generate all valid happy strings
    void solve(string &curr, vector<string> &res, int &n) {
        // If the string reaches length 'n', store it
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }

        // Try adding 'a', 'b', or 'c' while ensuring no adjacent duplicates
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (curr.empty() || curr.back() != ch) {
                curr.push_back(ch);
                solve(curr, res, n);
                curr.pop_back();  // Backtrack
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> res;

        // Generate all possible happy strings
        solve(curr, res, n);

        // Return k-th string (1-based index) or empty string if k is out of range
        return k > res.size() ? "" : res[k - 1];
    }
};


/**
 * Approach:
 * - We use **backtracking** to generate valid happy strings of length `n`.
 * - A **happy string** is a string where **no two adjacent characters** are the same.
 * - Instead of storing all happy strings, we **count** the valid ones until we reach `k`.
 * - If the `k`-th happy string is found, we store it in `res` and terminate recursion early.
 *
 * Intuition:
 * - We explore all valid choices (`'a'`, `'b'`, `'c'`), ensuring the last character doesn't repeat.
 * - We **track the count (`cnt`)** of generated strings and stop once `cnt == k`.
 * - This **optimizes memory usage** by avoiding storage of all happy strings.
 *
 * Time Complexity:
 * - **O(3^N)** in the worst case, but **early termination** reduces the actual runtime.
 *
 * Space Complexity:
 * - **O(N)** for the recursive stack.
 */

class Solution {
public:
    // Backtracking function to generate happy strings
    void solve(string &curr, string &res, int &n, int &k, int &cnt) {
        // If the string reaches length 'n', count it
        if (curr.size() == n) {
            cnt++;
            if (cnt == k) { // Store the k-th string and terminate early
                res = curr;
            }
            return;
        }

        // Try adding 'a', 'b', or 'c' ensuring no adjacent duplicates
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (curr.empty() || curr.back() != ch) {
                curr.push_back(ch);
                solve(curr, res, n, k, cnt);
                if (cnt == k) return; // Stop recursion early if found
                curr.pop_back();  // Backtrack
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string res = "";
        int cnt = 0;

        // Generate happy strings and stop at k-th
        solve(curr, res, n, k, cnt);

        return res; // Return k-th happy string or empty string if k is invalid
    }
};