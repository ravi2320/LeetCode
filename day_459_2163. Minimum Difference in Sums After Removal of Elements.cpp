/*
2163. Minimum Difference in Sums After Removal of Elements
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given a 0-indexed integer array nums consisting of 3 * n elements.

You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:

The first n elements belonging to the first part and their sum is sumfirst.
The next n elements belonging to the second part and their sum is sumsecond.
The difference in sums of the two parts is denoted as sumfirst - sumsecond.

For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
Return the minimum difference possible between the sums of the two parts after the removal of n elements.

 

Example 1:

Input: nums = [3,1,2]
Output: -1
Explanation: Here, nums has 3 elements, so n = 1. 
Thus we have to remove 1 element from nums and divide the array into two equal parts.
- If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
- If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
- If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
The minimum difference between sums of the two parts is min(-1,1,2) = -1. 
Example 2:

Input: nums = [7,9,5,8,1,3]
Output: 1
Explanation: Here n = 2. So we must remove 2 elements and divide the remaining array into two parts containing two elements each.
If we remove nums[2] = 5 and nums[3] = 8, the resultant array will be [7,9,1,3]. The difference in sums will be (7+9) - (1+3) = 12.
To obtain the minimum difference, we should remove nums[1] = 9 and nums[4] = 1. The resultant array becomes [7,5,8,3]. The difference in sums of the two parts is (7+5) - (8+3) = 1.
It can be shown that it is not possible to obtain a difference smaller than 1.
 

Constraints:

nums.length == 3 * n
1 <= n <= 105
1 <= nums[i] <= 105
*/

/*
Approach:
- The array `nums` is of size `3n`. We are to partition it into three parts of size `n` each such that the difference between the sum of the first and the third part is minimized.
- We use two heaps:
  1. A max-heap (`maxPQ`) to keep track of the `n` smallest elements from the *left* side.
  2. A min-heap (`minPQ`) to keep track of the `n` largest elements from the *right* side.
- We build two arrays:
  1. `leftMin[i]` stores the minimum sum of `n` elements picked from the first `i+1` elements.
  2. `rightMax[i]` stores the maximum sum of `n` elements picked from the last `n - i` elements.
- Finally, we iterate through the valid mid-points and calculate the difference between left and right sums.

Intuition:
- To minimize the difference between the left and right group sums, we greedily take the smallest `n` elements from the left (minimize sum) and the largest `n` elements from the right (maximize sum).
- We use heaps for efficient tracking of the `n` largest/smallest elements.

Time Complexity: O(n log n)
- We process each element with a heap operation (push + pop), each in O(log n), for 2n elements.

Space Complexity: O(n)
- We use additional arrays of size `n` and heaps with at most `n` elements.
*/

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int part = n / 3;  // Each partition size is n/3

        // Step 1: Calculate prefix min sums using max heap
        vector<long long> leftMin(n, 0);
        priority_queue<int> maxPQ;
        long long sum = 0;

        for (int i = 0; i < n - part; i++) {
            maxPQ.push(nums[i]);
            sum += nums[i];

            // Keep only 'part' smallest elements in maxPQ
            if (maxPQ.size() > part) {
                sum -= maxPQ.top();
                maxPQ.pop();
            }

            leftMin[i] = sum;
        }

        // Step 2: Calculate suffix max sums using min heap
        vector<long long> rightMax(n, 0);
        priority_queue<int, vector<int>, greater<int>> minPQ;
        sum = 0;

        for (int i = n - 1; i >= part; i--) {
            minPQ.push(nums[i]);
            sum += nums[i];

            // Keep only 'part' largest elements in minPQ
            if (minPQ.size() > part) {
                sum -= minPQ.top();
                minPQ.pop();
            }

            rightMax[i] = sum;
        }

        // Step 3: Minimize the difference between left sum and right sum
        long long diff = LLONG_MAX;
        for (int i = part - 1; i < n - part; i++) {
            diff = min(diff, leftMin[i] - rightMax[i + 1]);
        }

        return diff;
    }
};
