/*
873. Length of Longest Fibonacci Subsequence
Solved
Medium
Topics
Companies
A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

 

Example 1:

Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: arr = [1,3,7,11,12,14,18]
Output: 3
Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
 

Constraints:

3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 109
*/

/**
 * Approach:
 * - Use a **recursive function with memoization** (`dp[j][k]`) to find the longest Fibonacci sequence.
 * - Maintain a **hash map (`mp`)** to store indices of array elements for quick lookup.
 * - **Base Case**: If no valid sequence is found, return length `2` (since a Fibonacci sequence needs at least two elements).
 *
 * 🔹 **Time Complexity**: O(N²) → Each pair (j, k) is checked at most once.
 * 🔹 **Space Complexity**: O(N²) for DP table + O(N) for hashmap.
 */

class Solution {
public:
    // Recursive function to find Fibonacci subsequence length
    int solve(int j, int k, vector<int> &arr, unordered_map<int, int> &mp, vector<vector<int>> &dp){
        if(dp[j][k] != -1) {
            return dp[j][k];  // Return memoized result
        }

        int target = arr[k] - arr[j];  // Expected previous element in Fibonacci sequence

        if(mp.count(target) && mp[target] < j) {  // If `target` exists before `j`
            int i = mp[target];
            return dp[j][k] = solve(i, j, arr, mp, dp) + 1;
        }

        return dp[j][k] = 2;  // Default length if no valid sequence found
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;  // Stores element index for quick lookup
        vector<vector<int>> dp(n, vector<int>(n, -1));  // Memoization table

        // Store indices of each element in hashmap
        for(int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        int maxLen = 0;
        for(int j = 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int len = solve(j, k, arr, mp, dp);
                if(len >= 3) {
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};
	
	
/**
 * Approach:
 * - Use a **2D DP table (`dp[j][k]`)**, where:
 *   - `dp[j][k]` stores the **longest Fibonacci subsequence ending at `arr[j]` and `arr[k]`**.
 * - Maintain a **hash map (`mp`)** to store indices of elements for quick lookups.
 * - If `arr[k] - arr[j]` exists in `mp` and is at index `i < j`, we extend `dp[i][j]` to `dp[j][k]`.
 * - If no sequence is found, return `0` (since at least 3 elements are needed).
 *
 * 🔹 **Time Complexity**: O(N²) → Checks all (j, k) pairs.
 * 🔹 **Space Complexity**: O(N²) → For DP table + O(N) for hashmap.
 */

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;  // Maps values to their indices

        // Store element indices in the map
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));  // Initialize DP table with minimum length 2
        int maxLen = 0;

        // Iterate through all possible pairs (j, k)
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int target = arr[k] - arr[j];  // The expected previous element

                // Check if `target` exists and comes before `j`
                if (mp.count(target) && mp[target] < j) {
                    int i = mp[target];  // Index of `target`
                    dp[j][k] = dp[i][j] + 1;  // Extend the Fibonacci sequence
                }

                maxLen = max(maxLen, dp[j][k]);  // Update the max length found
            }
        }

        return maxLen >= 3 ? maxLen : 0;  // Ensure a valid Fibonacci sequence has at least 3 elements
    }
};