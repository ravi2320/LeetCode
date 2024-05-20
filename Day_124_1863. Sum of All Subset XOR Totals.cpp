/*
1863. Sum of All Subset XOR Totals
Solved
Easy
Topics
Companies
Hint
The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

 

Example 1:

Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
Example 2:

Input: nums = [5,1,6]
Output: 28
Explanation: The 8 subsets of [5,1,6] are:
- The empty subset has an XOR total of 0.
- [5] has an XOR total of 5.
- [1] has an XOR total of 1.
- [6] has an XOR total of 6.
- [5,1] has an XOR total of 5 XOR 1 = 4.
- [5,6] has an XOR total of 5 XOR 6 = 3.
- [1,6] has an XOR total of 1 XOR 6 = 7.
- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
Example 3:

Input: nums = [3,4,5,6,7,8]
Output: 480
Explanation: The sum of all XOR totals for every subset is 480.
 

Constraints:

1 <= nums.length <= 12
1 <= nums[i] <= 20
*/

// Intuition:
// - We generate all possible subsets of the given array using backtracking.
// - For each subset, we calculate the XOR of all its elements and sum up these XOR values.
// - Finally, we return the total sum.

// Time Complexity: O(2^N), where N is the number of elements in the input array.
// - We generate all possible subsets, which can be up to 2^N.

// Space Complexity: O(N * 2^N).
// - In the worst case, we generate all possible subsets, each containing up to N elements.

class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& currSubset, vector<vector<int>>& subsets) {
        if (i == nums.size()) {
            subsets.push_back(currSubset);
            return;
        }

        // Include the current element in the subset
        currSubset.push_back(nums[i]);
        solve(nums, i + 1, currSubset, subsets);
        currSubset.pop_back(); // Backtrack by removing the current element from the subset

        // Exclude the current element from the subset
        solve(nums, i + 1, currSubset, subsets);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSubset;
        int sum = 0;

        solve(nums, 0, currSubset, subsets);

        // Calculate the XOR sum of each subset and accumulate the result
        for (auto& subset : subsets) {
            int XOR = 0;
            for (int& num : subset) {
                XOR ^= num;
            }
            sum += XOR;
        }

        return sum;
    }
};
