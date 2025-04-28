/*
2302. Count Subarrays With Score Less Than K
Solved
Hard
Topics
Companies
Hint
The score of an array is defined as the product of its sum and its length.

For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [2,1,4,3,5], k = 10
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3. 
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.
Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.
Example 2:

Input: nums = [1,1,1], k = 5
Output: 5
Explanation:
Every subarray except [1,1,1] has a score less than 5.
[1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
Thus, there are 5 subarrays having scores less than 5.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 1015
*/

/*
Intuition:
- We need to count the number of subarrays where (sum of subarray) * (length of subarray) < k.
- Use a **two-pointer (sliding window)** approach to maintain a valid window:
    - Expand the window by moving `j`.
    - Shrink the window from the left (`i`) if the condition is violated.
- At each valid position, the number of valid subarrays ending at `j` is (j - i + 1).

Approach:
- Initialize two pointers `i` and `j` at 0.
- Maintain `sum` of elements between i and j.
- If `sum * (length)` >= k, move `i` to reduce the window until it's valid.
- For each valid `j`, add (j - i + 1) to the answer.

Time Complexity: O(N)
- Each element is added and removed at most once from the window.

Space Complexity: O(1)
- Constant extra space.

*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        long long sum = 0;

        // Use two pointers to maintain the window
        while (j < n) {
            sum += nums[j];

            // Shrink the window if condition fails
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }

            // All subarrays ending at j and starting from i to j are valid
            ans += (j - i + 1);

            j++;
        }

        return ans;
    }
};
