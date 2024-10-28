/*
338. Counting Bits
Solved
Easy
Topics
Companies
Hint
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105
*/

/*
Approach:
1. Iterate from 0 to `n` and calculate the number of 1-bits (set bits) for each integer `i`.
2. For each integer `i`, initialize `cnt` to store the count of set bits.
3. Use a while loop to count the set bits of `i`:
   - Use `num & 1` to check if the least significant bit is 1.
   - Right shift `num` by 1 to move through all bits of `i`.
4. Append `cnt` to the result vector `res`.
5. Return `res` containing the count of set bits for each integer from 0 to `n`.

Time Complexity: O(n * log(n)), where `n` is the input value, as we check each bit for numbers from 0 to `n`.
Space Complexity: O(n), for storing results.

*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;  // Stores count of set bits for each number from 0 to n

        for(int i = 0; i <= n; i++) {
            int cnt = 0;  // Count of set bits for current number `i`
            int num = i;

            while(num > 0) {
                cnt += num & 1;  // Increment if least significant bit is 1
                num = num >> 1;  // Shift bits to the right by 1
            }

            res.push_back(cnt);  // Store count of set bits for `i`
        }

        return res;
    }
};
