/*
1346. Check If N and Its Double Exist
Solved
Easy
Topics
Companies
Hint
Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
Example 2:

Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.
 

Constraints:

2 <= arr.length <= 500
-103 <= arr[i] <= 103
*/

/*
Approach:
1. **Brute Force**:
   - Use two nested loops to compare all pairs of elements in the array.
   - Check if any element `arr[i]` equals `2 * arr[j]` where `i != j`.

2. **Edge Cases**:
   - The array contains zeroes (as `2 * 0 = 0`).
   - Negative numbers and their double values.

Time Complexity:
- **O(n²)**: Nested loops iterate over all possible pairs in the array.

Space Complexity:
- **O(1)**: No additional data structures are used.

Optimization:
- This implementation can be optimized to O(n) using a hash set for constant-time lookups.

*/

class Solution {
public:
    // Function to check if there exists two indices i and j such that arr[i] = 2 * arr[j]
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        // Iterate through all pairs in the array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Skip if the indices are the same
                if (i == j) continue;

                // Check if one element is double the other
                if (arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }

        // Return false if no such pair is found
        return false;
    }
};
