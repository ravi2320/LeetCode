/*
2657. Find the Prefix Common Array of Two Arrays
Solved
Medium
Topics
Companies
Hint
You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

 

Example 1:

Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
Example 2:

Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
 

Constraints:

1 <= A.length == B.length == n <= 50
1 <= A[i], B[i] <= n
It is guaranteed that A and B are both a permutation of n integers.
*/

/*
Approach:
1. Traverse both arrays `A` and `B` simultaneously.
2. Use a set to track elements that have been seen so far from both arrays.
3. Maintain a counter `cnt` to count the common elements between the prefixes of `A` and `B` at each index.
4. For each index `i`:
   - Check if the current element of `A` or `B` has already been seen in the set.
   - Increment the counter if it's found in the set.
   - Add the current elements of `A` and `B` to the set.
5. Add the counter value to the result vector after processing each index.

Intuition:
- By using a set, we can efficiently track the elements seen so far and identify common elements in the prefixes of `A` and `B`.

Time Complexity:
- \(O(n)\): Linear traversal of both arrays with constant-time operations for set insertion and lookup.
  
Space Complexity:
- \(O(n)\): Space required to store elements in the set.

Edge Cases:
1. Arrays `A` and `B` have no common elements.
2. Arrays `A` and `B` are identical.
3. Arrays with varying distributions of common elements.

*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(); // Size of the arrays
        unordered_set<int> seenElements; // Set to store seen elements
        int cnt = 0; // Counter for common elements
        vector<int> ans; // Result array to store prefix common counts

        // Traverse both arrays
        for (int i = 0; i < n; i++) {
            // Check if current element of A is already in the set
            if (seenElements.find(A[i]) != seenElements.end()) {
                cnt++; // Increment count if already seen
            }
            seenElements.insert(A[i]); // Add element of A to the set

            // Check if current element of B is already in the set
            if (seenElements.find(B[i]) != seenElements.end()) {
                cnt++; // Increment count if already seen
            }
            seenElements.insert(B[i]); // Add element of B to the set

            // Add the current count of common elements to the result
            ans.push_back(cnt);
        }

        return ans; // Return the prefix common array
    }
};