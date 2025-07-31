/*
898. Bitwise ORs of Subarrays

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.
Example 2:

Input: arr = [1,1,2]
Output: 3
Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.
Example 3:

Input: arr = [1,2,4]
Output: 6
Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
 

Constraints:

1 <= arr.length <= 5 * 104
0 <= arr[i] <= 109
*/

// ✅ Approach:
// 1. Use two hash sets: `prev` to store all results of bitwise ORs ending at the previous element,
//    and `curr` to store all results ending at the current element.
// 2. For each element in the array:
//    - For each OR result `x` from the previous iteration, compute `x | arr[i]` and insert into `curr` and result set `res`.
//    - Also insert `arr[i]` itself into both `curr` and `res` (as new subarrays start at this element).
// 3. At each step, update `prev = curr` and clear `curr`.
// 4. At the end, the size of `res` gives the count of distinct bitwise OR values for all subarrays.

// ✅ Intuition:
// Bitwise OR is cumulative and only increases or maintains bit positions (never unsets bits). 
// So, for each element, we only need to OR it with the results from the previous element’s ORs.
// This limits the number of combinations significantly even for large arrays.

// ✅ Time Complexity: O(N * 30)
// Because for each of the N elements, the number of unique OR results is bounded by the number of bits in an integer (max ~30).
// ✅ Space Complexity: O(N * 30)
// Due to storage in `res`, `curr`, and `prev` which hold OR values.

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> prev; // OR values from previous iteration
        unordered_set<int> curr; // OR values for current iteration
        unordered_set<int> res;  // Final set of all unique OR values

        for(int i = 0; i < n; i++) {
            // Step 1: OR current value with all previous ORs
            for(const int &x : prev) {
                int orVal = x | arr[i];
                curr.insert(orVal);  // Add to current ORs
                res.insert(orVal);   // Add to result set
            }

            // Step 2: Add current element as a new subarray
            curr.insert(arr[i]);
            res.insert(arr[i]);

            // Step 3: Prepare for next iteration
            prev = curr;
            curr.clear();
        }

        return res.size(); // Total distinct OR results
    }
};
