/*
386. Lexicographical Numbers
Solved
Medium
Topics
Companies
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 

Constraints:

1 <= n <= 5 * 104
*/

/*
Approach:
1. **Recursive Function**: The `solve` function generates numbers by appending digits from 0 to 9 to the current number (`num`). It explores all possible numbers that can be formed while ensuring they do not exceed `n`.
   
2. **Base Case**: If the current number (`num`) exceeds `n`, the function returns without further processing.

3. **Generating Numbers**: 
   - Start from each digit from 1 to 9 and recursively build numbers by appending digits.
   - Each valid number is added to the result vector `res`.

4. **Lexical Order**: By starting from 1 to 9 and recursively appending digits, the numbers are naturally generated in lexicographical order.

Time Complexity:
- **O(n)**: Each number up to `n` is visited at most once during the recursive calls.

Space Complexity:
- **O(log n)**: The space used by the recursion stack, which can go up to the number of digits in `n`.

*/

class Solution {
public:
    void solve(int num, int n, vector<int> &res) {
        // If the current number exceeds n, stop further processing
        if (num > n) return;

        // Add the current number to the result
        res.push_back(num);

        // Generate numbers by appending digits 0-9
        for (int append = 0; append <= 9; append++) {
            int newNum = num * 10 + append;

            // If the new number exceeds n, stop further processing
            if (newNum > n) return;

            // Recursive call with the new number
            solve(newNum, n, res);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> res;

        // Start the recursive process from each digit 1-9
        for (int start = 1; start <= 9; start++) {
            solve(start, n, res);
        }

        return res; // Return the final result
    }
};
