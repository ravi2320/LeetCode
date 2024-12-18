/*
1423. Maximum Points You Can Obtain from Cards
Solved
Medium
Topics
Companies
Hint
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 

Constraints:

1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length
*/

/*
Approach:
1. Use a **sliding window** technique to calculate the maximum score achievable by selecting exactly `k` cards.
2. Start by considering all `k` cards from the left (initial left sum).
3. Gradually decrease the count of left-side cards while increasing the count of right-side cards:
   - Subtract from the left sum and add to the right sum.
   - Update the maximum score at each step.

Steps:
1. Calculate the initial sum of the first `k` cards (leftSum).
2. Initialize `rightSum` to 0 and `maxPoints` to `leftSum`.
3. Iteratively reduce the left sum and add to the right sum:
   - Adjust `leftSum` by subtracting the leftmost card in the current window.
   - Add a card from the right to `rightSum`.
   - Update the maximum score using the sum of `leftSum` and `rightSum`.
4. Return the maximum score.

Time Complexity:
- O(k): To calculate the initial left sum.
- O(k): For the sliding window traversal.
- Overall: O(k).

Space Complexity:
- O(1): No additional space is used.

Edge Cases:
- `k == n` (use all cards).
- Cards have negative values.
- Cards array size is 1.

*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0;
        int n = cardPoints.size();

        // Calculate the sum of the first k cards
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        // Initialize the maximum score with the initial left sum
        int maxPoints = leftSum;

        // Traverse from the end of the array, adjusting leftSum and rightSum
        int j = n - 1; // Pointer for the right side
        for (int i = k - 1; i >= 0; i--) {
            leftSum -= cardPoints[i]; // Remove the leftmost card in the current window
            rightSum += cardPoints[j--]; // Add a card from the right side

            // Update the maximum score
            maxPoints = max(maxPoints, leftSum + rightSum);
        }

        return maxPoints; // Return the maximum score
    }
};
