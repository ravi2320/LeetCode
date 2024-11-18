/*
1652. Defuse the Bomb
Solved
Easy
Topics
Companies
Hint
You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

 

Example 1:

Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
Example 2:

Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]
Explanation: When k is zero, the numbers are replaced by 0. 
Example 3:

Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
 

Constraints:

n == code.length
1 <= n <= 100
1 <= code[i] <= 100
-(n - 1) <= k <= n - 1
*/

/*
Approach:
1. Given an array `code` of size `n` and an integer `k`, the task is to generate a decrypted version of the array based on the following rules:
   - If `k == 0`, return an array of size `n` filled with 0.
   - If `k > 0`, the `i`th element of the result should be the sum of the next `k` elements from `code` in a circular manner.
   - If `k < 0`, the `i`th element of the result should be the sum of the previous `|k|` elements from `code` in a circular manner.
   
2. To handle the circular behavior, modulo operations are used to wrap indices around.

Steps:
1. Initialize `result` vector of size `n` with zeros.
2. If `k == 0`, directly return `result`.
3. For each index `i`:
   - If `k > 0`, sum the next `k` elements in a circular fashion.
   - If `k < 0`, sum the previous `|k|` elements in a circular fashion.
4. Use modulo operations to handle index wrapping.

Time Complexity:
- O(n * |k|) — Each element requires iterating `|k|` times.
  
Space Complexity:
- O(n) — The output array `result` of size `n`.

*/

class Solution {
public:
    // Function to decrypt the array based on the value of k
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0); // Initialize the result array with zeros

        // Case when k is 0, return an array of zeros
        if (k == 0) {
            return result;
        }

        // Iterate through each element of the code
        for (int i = 0; i < n; i++) {
            // If k is negative, sum the previous |k| elements
            if (k < 0) {
                for (int j = i - abs(k); j < i; j++) {
                    result[i] += code[(j + n) % n]; // Use modulo for circular behavior
                }
            } 
            // If k is positive, sum the next k elements
            else {
                for (int j = i + 1; j < i + k + 1; j++) {
                    result[i] += code[j % n]; // Use modulo for circular behavior
                }
            }
        }
        return result;
    }
};
