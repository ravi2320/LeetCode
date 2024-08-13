/*
40. Combination Sum II
Solved
Medium
Topics
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

/*
Intuition:
- The problem is about finding all unique combinations of elements that sum up to a given target. 
- Elements in the combination should be non-repeating and should maintain the sorted order. 
- The solution involves backtracking where at each step, we either pick the current element or move to the next.

Time Complexity:
- Sorting the array takes O(n log n), where n is the number of candidates.
- The backtracking approach may take O(2^n) in the worst case, where n is the number of candidates, as it explores all possible combinations.

Space Complexity:
- The space complexity is O(k), where k is the number of elements in the current combination, because of the recursion stack.
*/

class Solution {
public:
    // Helper function to perform the backtracking
    void solve(vector<int>& candidates, int target, int idx, vector<int> &curr, vector<vector<int>> &res){

        // Base case: If the target becomes negative, no need to proceed
        if(target < 0) return;

        // If we hit the exact target, we add the current combination to the results
        if(target == 0){
            res.push_back(curr);
            return;
        }

        // Iterate over the candidates starting from the current index
        for(int i = idx; i < candidates.size(); i++){
            // Skip duplicates to ensure unique combinations
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            // Include the current candidate in the combination
            curr.push_back(candidates[i]);

            // Recurse with reduced target and move to the next index
            solve(candidates, target - candidates[i], i + 1, curr, res);

            // Backtrack by removing the last included candidate
            curr.pop_back();
        }
    }

    // Main function to find unique combinations
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;  // To store the result combinations
        vector<int> curr;         // To store the current combination

        // Sort candidates to handle duplicates and maintain order
        sort(candidates.begin(), candidates.end());

        // Start backtracking from index 0
        solve(candidates, target, 0, curr, res);

        return res;  // Return the final result containing all unique combinations
    }
};
