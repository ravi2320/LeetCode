/*
2275. Largest Combination With Bitwise AND Greater Than Zero
Solved
Medium
Topics
Companies
Hint
The bitwise AND of an array nums is the bitwise AND of all integers in nums.

For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
Also, for nums = [7], the bitwise AND is 7.
You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.

Return the size of the largest combination of candidates with a bitwise AND greater than 0.

 

Example 1:

Input: candidates = [16,17,71,62,12,24,14]
Output: 4
Explanation: The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 & 24 = 16 > 0.
The size of the combination is 4.
It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.
Note that more than one combination may have the largest size.
For example, the combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.
Example 2:

Input: candidates = [8,8]
Output: 2
Explanation: The largest combination [8,8] has a bitwise AND of 8 & 8 = 8 > 0.
The size of the combination is 2, so we return 2.
 

Constraints:

1 <= candidates.length <= 105
1 <= candidates[i] <= 107
*/

/*
Approach:
1. For each bit position in the numbers, we count how many numbers in the `candidates` array have that specific bit set to 1.
2. We iterate over each bit position up to the maximum number of bits required (we approximate this with `log2(10000007) + 1`).
3. For each bit position, we use bitwise AND to check if the bit is set for each number.
4. We keep track of the maximum count of numbers with the bit set in any position, which is our result.

Time Complexity: O(n * log(maxCandidate)), where n is the size of `candidates` and log(maxCandidate) is the number of bits in the largest number.
Space Complexity: O(1), only a few extra variables are used.

*/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 1;
        int reqBits = log2(10000007) + 1; // Approximate maximum bits needed

        // Iterating over each bit position
        for(int bitPos = 0; bitPos < reqBits; bitPos++) {
            int cnt = 0;

            // Counting numbers with the current bit set
            for(int &num : candidates) {
                if(num & (1 << bitPos)) {
                    cnt++;
                }
            }

            // Updating result with the maximum count found for any bit position
            res = max(res, cnt);
        }

        return res;
    }
};
