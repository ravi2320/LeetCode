/*
2554. Maximum Number of Integers to Choose From a Range I
Solved
Medium
Topics
Companies
Hint
You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

The chosen integers have to be in the range [1, n].
Each integer can be chosen at most once.
The chosen integers should not be in the array banned.
The sum of the chosen integers should not exceed maxSum.
Return the maximum number of integers you can choose following the mentioned rules.

 

Example 1:

Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
Example 2:

Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned conditions.
Example 3:

Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.
 

Constraints:

1 <= banned.length <= 104
1 <= banned[i], n <= 104
1 <= maxSum <= 109
*/

/*
Approach:
1. Use an unordered set to store the banned numbers for O(1) lookup.
2. Iterate through numbers from 1 to `n`:
   - If a number is not banned, check if adding it to the current sum does not exceed `maxSum`.
   - If the condition is satisfied, increment the count and add the number to the sum.
   - Break the loop if the sum exceeds `maxSum`.
3. Return the count of numbers added to the sum.

Time Complexity:
- **O(n)**: Iterate through numbers from 1 to `n`, with O(1) lookup for banned numbers in the set.

Space Complexity:
- **O(k)**: Additional space for the unordered set, where `k` is the size of the `banned` array.

*/

class Solution {
public:
    // Function to calculate the maximum count of numbers satisfying the conditions
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Store banned numbers in a set for quick lookup
        unordered_set<int> st(banned.begin(), banned.end());

        long long cnt = 0; // Count of numbers added
        long long sum = 0; // Current sum of numbers

        // Iterate through numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end()) { // Check if the number is not banned
                if (sum + i <= maxSum) { // Check if adding the number does not exceed maxSum
                    cnt++; // Increment count
                    sum += i; // Add the number to the sum
                } else {
                    break; // Stop if adding the number exceeds maxSum
                }
            }
        }

        return cnt; // Return the count of numbers
    }
};
