/*
2028. Find Missing Observations
Solved
Medium
Topics
Companies
Hint
You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.

You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.

 

Example 1:

Input: rolls = [3,2,4,3], mean = 4, n = 2
Output: [6,6]
Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
Example 2:

Input: rolls = [1,5,6], mean = 3, n = 4
Output: [2,3,2,2]
Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.
Example 3:

Input: rolls = [1,2,3,4], mean = 6, n = 4
Output: []
Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.
 

Constraints:

m == rolls.length
1 <= n, m <= 105
1 <= rolls[i], mean <= 6
*/

/*
**Problem Statement:**
- Given a list of observed rolls of a dice (`rolls`), a mean value for all dice rolls (including unobserved rolls), and the number of missing dice rolls (`n`), determine the values of the missing dice rolls such that the overall mean is maintained.
- The dice has six faces, and the values on each dice roll must be between 1 and 6.

**Approach:**
1. **Calculate Total Sum of All Rolls:**
   - The total number of dice rolls is `m + n`, where `m` is the number of observed rolls (length of `rolls`), and `n` is the number of missing rolls.
   - The total sum of all rolls can be computed as `(m + n) * mean`.

2. **Calculate Missing Sum:**
   - Subtract the sum of the observed rolls from the total sum to get the sum required for the missing rolls.

3. **Check for Validity:**
   - If the required sum for the missing rolls is less than `n` (minimum possible sum if all missing rolls are 1) or greater than `6 * n` (maximum possible sum if all missing rolls are 6), it's impossible to satisfy the condition, so return an empty array.

4. **Distribute the Sum:**
   - Divide the required sum for the missing rolls evenly across `n` missing rolls. Any remainder is distributed by incrementing some of the rolls by 1 until the remainder is zero.

5. **Time Complexity:**
   - O(n) where `n` is the number of missing rolls because we loop through `n` to distribute the sum.

6. **Space Complexity:**
   - O(n) for the array storing the result.

**Example Usage:**
- Given `rolls = [3, 2, 4]`, `mean = 4`, and `n = 2`, the missing rolls are `[6, 4]`.
*/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        // Calculate the total sum that is required for all the rolls
        int totalSum = (m + n) * mean;
        // Calculate the sum of the observed rolls
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        // Calculate the sum required for the missing rolls
        totalSum -= sum;
        
        // If the required sum for the missing rolls is not possible
        if(totalSum < n || totalSum > 6 * n)
            return {};

        // Calculate the quotient (div) and remainder (rem) when dividing the total sum by n
        int div = totalSum / n;
        int rem = totalSum % n;
        vector<int> ans(n);

        // Distribute the quotient value and add remainder as necessary
        for(int i = 0; i < n; i++){
            ans[i] = div;  // Assign the base value
            if(rem > 0){   // Add 1 if there's a remainder
                ans[i]++;
                rem--;
            }
        }

        return ans;
    }
};
