/*
2140. Solving Questions With Brainpower
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.

 

Example 1:

Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
Example 2:

Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
 

Constraints:

1 <= questions.length <= 105
questions[i].length == 2
1 <= pointsi, brainpoweri <= 105
*/

/*
Approach:
1. **Recursive + Memoization (Top-Down DP)**:
   - Define `solve(idx)`: maximum points that can be obtained starting from index `idx`.
   - At each index, we have two choices:
     - **Take the current question**: Add its points and jump to the next valid index (idx + `brainpower` + 1).
     - **Skip the current question**: Move to the next index.
   - Use memoization (`dp` array) to store results and avoid recomputation.

Intuition:
- Since each question has a penalty (`brainpower`), skipping some questions might be optimal.
- The problem has **overlapping subproblems** (same `idx` might be solved multiple times).
- **Optimal substructure** exists since the best solution for `idx` depends on subproblems (`idx+1` and `idx + brainpower + 1`).
- Hence, **Dynamic Programming (DP) is ideal**.

Time Complexity: **O(n)** - Each index is computed once and stored in `dp`.
Space Complexity: **O(n)** - `dp` array stores results for all indices.
*/

class Solution {
    int n;
public:
    long long solve(int idx, vector<vector<int>>& questions, vector<long long> &dp){
        // Base case: If index exceeds limit, return 0
        if(idx >= n) return 0;

        // If already computed, return stored result
        if(dp[idx] != -1) return dp[idx];

        // Option 1: Take the current question and jump to the next valid question
        long long take = questions[idx][0] + solve(idx + questions[idx][1] + 1, questions, dp);

        // Option 2: Skip the current question
        long long skip = solve(idx + 1, questions, dp);

        // Store and return the maximum of both options
        return dp[idx] = max(take, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        vector<long long> dp(n, -1); // Memoization array
        return solve(0, questions, dp);
    }
};


/*
Approach:
1. **Bottom-Up Dynamic Programming (Tabulation)**:
   - Define `dp[i]`: Maximum points that can be earned starting from index `i`.
   - Iterate **backward** (from `n-1` to `0`), since future states depend on current ones.
   - At each index, we have two choices:
     - **Take the current question**: Add its points and jump to the next valid index (`i + brainpower + 1`).
     - **Skip the current question**: Move to the next index.
   - Store the **maximum of both options** in `dp[i]`.
   - The result is stored in `dp[0]`.

Intuition:
- Since each question has a **penalty (brainpower)**, skipping some questions might be optimal.
- **Optimal substructure**: The best solution for `i` depends on `i + 1` and `i + brainpower + 1`.
- This allows **iterative DP** instead of recursion.
- **Tabulation avoids recursion overhead and optimizes space**.

Time Complexity: **O(n)** - We iterate over the array once.
Space Complexity: **O(n)** - We store results for all indices in `dp`.
*/

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0); // DP array to store max points from each index

        // Iterate backward (from last index to 0)
        for(int i = n - 1; i >= 0; i--) {
            // Option 1: Take the current question and jump to the next valid question
            long long take = questions[i][0] + (i + questions[i][1] + 1 >= n ? 0 : dp[i + questions[i][1] + 1]);

            // Option 2: Skip the current question
            long long skip = i + 1 >= n ? 0 : dp[i + 1];

            // Store the maximum points possible at this index
            dp[i] = max(take, skip);
        }

        return dp[0]; // The maximum points that can be earned from index 0
    }
};