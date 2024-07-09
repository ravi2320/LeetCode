/*
875. Koko Eating Bananas
Solved
Medium
Topics
Companies
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
*/

/*
 * Intuition:
 * The problem is to determine the minimum eating speed (k) at which Koko can finish all the bananas within `h` hours.
 * We can use a binary search approach to find the optimal eating speed efficiently.
 * The range of `k` is from 1 to the maximum number of bananas in any pile.
 * For each candidate `k`, we calculate the total hours needed and adjust our search range based on whether it is feasible to finish within `h` hours.
 *
 * Time Complexity: O(n log m), where n is the number of piles and m is the maximum number of bananas in a pile. Binary search runs in O(log m) and for each candidate `k`, we compute the total hours in O(n).
 * Space Complexity: O(1), as we only use a few extra variables for our calculations.
 */

class Solution {
public:
    // Helper function to find the maximum element in the piles array
    int maxElement(vector<int>& piles) {
        int maxi = piles[0];
        int n = piles.size();

        for (int i = 1; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    // Helper function to calculate the total hours required to eat all bananas at a given eating speed
    long long findRequiredHour(vector<int>& piles, int mid) {
        long long totalHour = 0;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            totalHour += (piles[i] + mid - 1) / mid;  // This is equivalent to ceil(piles[i] / mid)
        }

        return totalHour;
    }

    // Main function to find the minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxElement(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHours = findRequiredHour(piles, mid);

            if (totalHours <= h) {
                high = mid - 1;  // Try to find a lower feasible speed
            } else {
                low = mid + 1;   // Increase the speed
            }
        }

        return low;
    }
};
