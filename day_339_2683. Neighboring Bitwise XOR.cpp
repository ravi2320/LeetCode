/*
2683. Neighboring Bitwise XOR
Solved
Medium
Topics
Companies
Hint
A 0-indexed array derived with length n is derived by computing the bitwise XOR (⊕) of adjacent values in a binary array original of length n.

Specifically, for each index i in the range [0, n - 1]:

If i = n - 1, then derived[i] = original[i] ⊕ original[0].
Otherwise, derived[i] = original[i] ⊕ original[i + 1].
Given an array derived, your task is to determine whether there exists a valid binary array original that could have formed derived.

Return true if such an array exists or false otherwise.

A binary array is an array containing only 0's and 1's
 

Example 1:

Input: derived = [1,1,0]
Output: true
Explanation: A valid original array that gives derived is [0,1,0].
derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1 
derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0
Example 2:

Input: derived = [1,1]
Output: true
Explanation: A valid original array that gives derived is [0,1].
derived[0] = original[0] ⊕ original[1] = 1
derived[1] = original[1] ⊕ original[0] = 1
Example 3:

Input: derived = [1,0]
Output: false
Explanation: There is no valid original array that gives derived.
 

Constraints:

n == derived.length
1 <= n <= 105
The values in derived are either 0's or 1's
*/

/*
Approach:
1. The derived array is formed based on the XOR operation between consecutive elements of the original array.
   - `derived[i] = original[i] ^ original[i+1]` for all `0 <= i < n-1`
   - Additionally, the condition `derived[n-1] = original[n-1] ^ original[0]` must hold.
2. To verify if a valid original array exists:
   - Start by assuming `original[0] = 0` and compute the rest of the array.
   - Check if the final XOR condition (`original[0] ^ original[n-1] == derived[n-1]`) is satisfied.
   - If not, repeat the process with `original[0] = 1`.

Time Complexity:
- \(O(n)\): Two passes through the array (one for each assumption).

Space Complexity:
- \(O(1)\): The space used is constant as the derived array is processed in place without additional data structures.

*/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        // Case 1: Assume original[0] = 0 and compute the rest
        int originalFirst = 0;
        int originalLast = 0; // Tracks original[n-1]
        for (int i = 0; i < n; i++) {
            originalLast = originalFirst ^ derived[i]; // Compute the next value
            originalFirst = originalLast;             // Shift values for next iteration
        }

        // Check if the condition holds for the last element
        if (originalLast == 0) {
            return true;
        }

        // Case 2: Assume original[0] = 1 and compute again
        originalFirst = 1;
        originalLast = 1; // Reset for new computation
        for (int i = 0; i < n; i++) {
            originalLast = originalFirst ^ derived[i];
            originalFirst = originalLast;
        }

        // Check the condition for this case
        return originalLast == 1;
    }
};


/*
Approach:
1. Use the given XOR relationship: 
   - `derived[i] = original[i] ^ original[i+1]` for `0 <= i < n-1`.
   - The additional condition is `original[0] ^ original[n-1] == derived[n-1]`.
2. Starting from `original[0] = 0`, compute the remaining elements of the `original` array.
3. Check whether the computed array satisfies the condition `original[0] ^ original[n-1] == derived[n-1]`.

Optimization:
- Instead of explicitly constructing the `original` array, only track its values as needed.

Time Complexity:
- \(O(n)\): A single pass through the `derived` array.

Space Complexity:
- \(O(1)\): Uses only a few variables, no additional data structures.

*/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        // Simulate the XOR operations directly without storing the original array
        int originalFirst = 0; // Assume original[0] = 0
        int originalLast = 0;  // Tracks the value of original[n-1]
        
        for (int i = 0; i < n - 1; i++) {
            originalLast = originalFirst ^ derived[i];
            originalFirst = originalLast; // Shift values for the next computation
        }

        // Check if the XOR condition holds
        return (originalLast ^ 0) == derived[n-1];
    }
};

/*
Approach:
1. XOR all elements in the `derived` array.
2. If the result is `0`, return `true` (a valid `original` array exists).
3. Otherwise, return `false`.

Time Complexity:
- O(n): Single pass through the array.

Space Complexity:
- O(1): Constant space usage.
*/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int Xor = 0;

        // Compute the XOR of all elements in the derived array
        for (int &x : derived) {
            Xor ^= x;
        }

        // A valid array exists if the XOR is 0
        return Xor == 0;
    }
};
