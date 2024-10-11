/*
39. Combination Sum
Solved
Medium
Topics
Companies
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

/*
Approach:
1. Use backtracking to find all combinations that sum to the target.
2. For each element in candidates, we either pick it (and reduce the target), or we skip it.
3. Continue this process until we either find a valid combination (target == 0) or exceed the target.
4. Push the valid combination to the result and backtrack.

Time Complexity: O(2^n), where n is the size of candidates.
Space Complexity: O(n), for the recursion stack and storing results.
*/

class Solution {
public:
    void solve(int i, vector<int>& candidate, int target, vector<int> &arr, vector<vector<int>> &res) {
        // Base case: if we have reached the end of candidates
        if (i == candidate.size()) {
            if (target == 0) {
                res.push_back(arr); // If target is met, add current combination to the result
            }
            return;
        }

        // Pick the element if it doesn't exceed the target
        if (candidate[i] <= target) {
            arr.push_back(candidate[i]); // Include the current element in the combination
            solve(i, candidate, target - candidate[i], arr, res); // Recursively solve with updated target
            arr.pop_back(); // Backtrack to explore other combinations
        }

        // Move to the next element
        solve(i + 1, candidate, target, arr, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; // To store the result
        vector<int> arr; // Current combination
        
        // Start the recursive backtracking process
        solve(0, candidates, target, arr, res);
        
        return res;
    }
};
