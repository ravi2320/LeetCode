/*
 2616. Minimize the Maximum Difference of Pairs
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

 

Example 1:

Input: nums = [10,1,2,7,1,3], p = 2
Output: 1
Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
Example 2:

Input: nums = [4,2,1,2], p = 1
Output: 0
Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= p <= (nums.length)/2
*/

/*
Approach:
We aim to minimize the maximum difference among `p` pairs of adjacent elements in the array.
To solve this, we use **Binary Search on Answer** — the minimum possible value of the maximum
difference. 

For a candidate `maxDiff`, we use a greedy approach (in `isPossible`) to try to form `p` pairs
with adjacent elements such that each pair has a difference ≤ maxDiff.

Intuition:
- Sort the array first so that adjacent elements have the smallest differences.
- Try to greedily pair up adjacent elements whose difference ≤ mid (current guess).
- If we can form `p` such pairs, we try a smaller maxDiff. If not, we need to increase it.

Time Complexity: O(n log D)
Where `n` is the size of the array and `D` is the range of possible differences (max - min).
For each binary search step (log D), we scan the array once (O(n)).

Space Complexity: O(1)
Only a few variables used; sorting is done in-place.
*/

class Solution {
public:
    // Helper function to check if we can form at least `pairs` pairs with maxDiff
    bool isPossible(vector<int> &nums, int maxDiff, int pairs) {
        int cnt = 0;
        int n = nums.size();
        int i = 0;

        // Traverse and greedily form valid adjacent pairs
        while (i < n - 1) {
            // If the adjacent pair difference is within maxDiff
            if (nums[i + 1] - nums[i] <= maxDiff) {
                cnt++;      // Form a pair
                i += 2;     // Skip the next element (since it's used)
            } else {
                i++;        // Try next pair
            }

            // Early exit if enough pairs are formed
            if (cnt >= pairs) return true;
        }

        // Final check after loop
        return cnt >= pairs;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();

        // Sort the array so that smallest differences are between adjacent elements
        sort(nums.begin(), nums.end());

        long long low = 0;
        long long high = nums[n - 1] - nums[0];  // Maximum possible difference

        // Binary search on the minimum value of the maximum difference
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // If it's possible to form p pairs with maxDiff = mid, try smaller value
            if (isPossible(nums, mid, p)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;  // The minimum possible value of the maximum pair difference
    }
};
