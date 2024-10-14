/*
90. Subsets II
Solved
Medium
Topics
Companies
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

/*
Approach:
1. Use a recursive backtracking approach to generate all subsets.
2. Use a set to store subsets and avoid duplicates automatically.
3. Sort the input array to ensure that duplicates are easily handled.
4. The recursive function explores two possibilities at each index: 
   a. Include the current element in the subset.
   b. Exclude the current element from the subset.
5. Convert the set of subsets into a vector of vectors to return the result.

Time Complexity: O(2^n * n), where n is the length of the input array.
Space Complexity: O(2^n * n), where n is the length of the input array.
*/

class Solution {
public:
    // Recursive function to generate all subsets
    void solve(vector<int> &nums, int i, int n, vector<int> &curr, set<vector<int>> &st) {
        // If we've processed all elements, add the current subset to the set
        if (i == n) {
            st.insert(curr);
            return;
        }

        // Recursive call excluding the current element
        solve(nums, i + 1, n, curr, st);

        // Recursive call including the current element
        curr.push_back(nums[i]);
        solve(nums, i + 1, n, curr, st);
        curr.pop_back();  // Backtrack to remove the current element for other possibilities
    }

    // Main function to return all subsets without duplicates
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;  // Set to store subsets and handle duplicates
        vector<int> curr;     // Temporary vector to store the current subset

        // Sort the input array to group duplicates together
        sort(nums.begin(), nums.end());

        // Start the recursive function
        solve(nums, 0, nums.size(), curr, st);

        // Convert the set of subsets to a vector of vectors
        vector<vector<int>> res(st.begin(), st.end());

        return res;  // Return the final result
    }
};


/*
Approach:
1. Sort the array to ensure that duplicates are next to each other.
2. Use a recursive backtracking method to generate all subsets.
3. Skip over duplicate elements at each step to avoid adding the same subset more than once.
4. Each subset is stored in the result set.

Time Complexity: O(2^n), where n is the length of the input array.
Space Complexity: O(2^n), where n is the length of the input array.
*/

class Solution {
public:
    // Recursive function to generate all subsets
    void solve(int idx, vector<int> &nums, vector<int> &curr, vector<vector<int>> &res) {
        // Add the current subset to the result list
        res.push_back(curr);

        // Iterate through the remaining elements
        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates by ensuring that we do not process the same element consecutively
            if (i > idx && nums[i] == nums[i - 1]) continue;

            // Include the current element in the subset
            curr.push_back(nums[i]);

            // Recursive call to process the next element
            solve(i + 1, nums, curr, res);

            // Backtrack to explore other possibilities
            curr.pop_back();
        }
    }

    // Main function to return all subsets without duplicates
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;   // Stores the result subsets
        vector<int> curr;          // Temporary array to store the current subset

        // Sort the input array to handle duplicates easily
        sort(nums.begin(), nums.end());

        // Call the recursive backtracking function
        solve(0, nums, curr, res);

        return res;  // Return the final result
    }
};
