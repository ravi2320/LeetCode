/*
2966. Divide Array Into Arrays With Max Difference
Solved

avatar
Discuss Approach
arrow-up
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:

The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

 

Example 1:

Input: nums = [1,3,4,8,7,9,3,5,1], k = 2

Output: [[1,1,3],[3,4,5],[7,8,9]]

Explanation:

The difference between any two elements in each array is less than or equal to 2.

Example 2:

Input: nums = [2,4,2,2,5,2], k = 2

Output: []

Explanation:

Different ways to divide nums into 2 arrays of size 3 are:

[[2,2,2],[2,4,5]] (and its permutations)
[[2,2,4],[2,2,5]] (and its permutations)
Because there are four 2s there will be an array with the elements 2 and 5 no matter how we divide it. since 5 - 2 = 3 > k, the condition is not satisfied and so there is no valid division.

Example 3:

Input: nums = [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14

Output: [[2,2,12],[4,8,5],[5,9,7],[7,8,5],[5,9,10],[11,12,2]]

Explanation:

The difference between any two elements in each array is less than or equal to 14.

 

Constraints:

n == nums.length
1 <= n <= 105
n is a multiple of 3
1 <= nums[i] <= 105
1 <= k <= 105
*/

/*
Approach:
We are given an array `nums` and an integer `k`. The task is to divide the array into groups of 3 integers such that 
the maximum difference within each group is less than or equal to `k`.

Steps:
1. Sort the array to ensure consecutive triplets have minimal difference.
2. Traverse the array in steps of 3.
3. For each triplet (i, i+1, i+2), check if the difference between max and min (i.e., nums[i+2] - nums[i]) ≤ k.
   - If not, return an empty vector.
   - If yes, add the triplet to the result.

Intuition:
Sorting ensures that if a valid group of three exists, it must be formed by three consecutive elements. 
This greedy approach works because spreading values further apart would only increase the difference.

Time Complexity: O(n log n)
- Sorting takes O(n log n)
- One pass through the array: O(n)

Space Complexity: O(n)
- For storing the result triplets.
*/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // Step 1: Sort the array

        int n = nums.size();
        vector<vector<int>> ans;

        // Step 2: Iterate in groups of 3
        for (int i = 0; i < n; i += 3) {
            // Check if triplet has difference ≤ k
            if (nums[i + 2] - nums[i] > k) {
                return {};  // Invalid group
            }

            // Step 3: Add valid triplet
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return ans;  // Return all valid triplets
    }
};
