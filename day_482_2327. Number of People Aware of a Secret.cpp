/*
2327. Number of People Aware of a Secret

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 6, delay = 2, forget = 4
Output: 5
Explanation:
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
Example 2:

Input: n = 4, delay = 1, forget = 3
Output: 6
Explanation:
Day 1: The first person is named A. (1 person)
Day 2: A shares the secret with B. (2 people)
Day 3: A and B share the secret with 2 new people, C and D. (4 people)
Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6 people)
 

Constraints:

2 <= n <= 1000
1 <= delay < forget <= n
*/

/*
Approach:
1. Use recursion with memoization (Top-Down DP).
   - Define `solve(day, delay, forget)` as the number of people who first learn the secret on `day`.
   - Base case: On `day = 1`, one person initially knows the secret.
   - Transition: On `day`, the person could have learned it from some `prev` day.
     - They can only share after `delay` days.
     - They forget after `forget` days.
     - So valid `prev` days lie in the interval [day - forget + 1, day - delay].
   - Sum contributions from all valid `prev` days.

2. In `peopleAwareOfSecret`, calculate how many still remember the secret on the last day `n`.
   - Loop from `n - forget + 1` to `n` because these people have not forgotten yet.

Intuition:
- Each person starts sharing only after `delay` days and stops after `forget` days.
- Using DP avoids recalculating overlapping subproblems since the same "day" can be reached via multiple paths.
- Final answer = sum of all people who still remember the secret on day `n`.

Time Complexity: O(n * forget)  
- For each `day`, we may iterate over at most `forget` previous days.

Space Complexity: O(n)  
- Memoization array `dp` of size `n+1`.
*/

class Solution {
    int M = 1e9+7;      // Modulo to avoid overflow
    vector<int> dp;     // DP array for memoization

public:
    // Recursive DP: number of people who first know the secret on 'day'
    int solve(int day, int delay, int forget) {
        // Base case: day 1 → one person initially knows the secret
        if(day == 1) {
            return 1;
        }

        // Return already computed state
        if(dp[day] != -1) {
            return dp[day];
        }

        long long res = 0;

        // Check all possible "previous days" when they could have learned
        for(int prev = day - forget + 1; prev <= day - delay; prev++) {
            if(prev > 0) {
                res = (res + solve(prev, delay, forget)) % M;
            }
        }

        return dp[day] = res;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;
        dp.assign(n + 1, -1); // Initialize DP with -1 (uncomputed)

        // Count all people who still remember the secret on the last day
        for(int day = n - forget + 1; day <= n; day++) {
            if(day > 0) {
                total = (total + solve(day, delay, forget)) % M;
            }
        }

        return total % M;
    }
};
