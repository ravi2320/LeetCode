/*
2294. Partition Array Such That Maximum Difference Is K

arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.

Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [3,6,1,2,5], k = 2
Output: 2
Explanation:
We can partition nums into the two subsequences [3,1,2] and [6,5].
The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.
Example 2:

Input: nums = [1,2,3], k = 1
Output: 2
Explanation:
We can partition nums into the two subsequences [1,2] and [3].
The difference between the maximum and minimum value in the first subsequence is 2 - 1 = 1.
The difference between the maximum and minimum value in the second subsequence is 3 - 3 = 0.
Since two subsequences were created, we return 2. Note that another optimal solution is to partition nums into the two subsequences [1] and [2,3].
Example 3:

Input: nums = [2,2,4,5], k = 0
Output: 3
Explanation:
We can partition nums into the three subsequences [2,2], [4], and [5].
The difference between the maximum and minimum value in the first subsequences is 2 - 2 = 0.
The difference between the maximum and minimum value in the second subsequences is 4 - 4 = 0.
The difference between the maximum and minimum value in the third subsequences is 5 - 5 = 0.
Since three subsequences were created, we return 3. It can be shown that 3 is the minimum number of subsequences needed.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
0 <= k <= 105
*/

/*
Approach:
We are given an array `nums` and an integer `k`. We need to partition the array into the minimum number
of subsequences such that the difference between the maximum and minimum elements in each subsequence
is at most `k`.

Steps:
1. Sort the array so elements are in increasing order.
2. Iterate through the sorted array:
   - Start a new group with the current element.
   - Continue adding elements to the current group as long as the difference between
     the current element and the starting element is ≤ k.
3. Count the number of such groups formed.

Intuition:
Sorting ensures that consecutive elements are as close as possible.
A greedy approach ensures we minimize the number of partitions by forming the largest valid groups first.

Time Complexity: O(n log n)
- Sorting the array takes O(n log n)
- Single pass through the array: O(n)

Space Complexity: O(1)
- No extra space used apart from counters and loop variables.
*/

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // Sort the array

        int cnt = 0;  // Count of required partitions
        int n = nums.size();

        for (int i = 0; i < n;) {
            int start = nums[i];  // Start of current group
            cnt++;  // Start a new group
            i++;    // Include this element

            // Continue including elements as long as they are within `k` range from `start`
            while (i < n && nums[i] - start <= k) {
                i++;
            }
        }

        return cnt;  // Return total number of groups formed
    }
};
