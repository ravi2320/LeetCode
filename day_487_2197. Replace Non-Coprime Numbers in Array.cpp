/*
2197. Replace Non-Coprime Numbers in Array

avatar
Discuss Approach
arrow-up
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given an array of integers nums. Perform the following steps:

Find any two adjacent numbers in nums that are non-coprime.
If no such numbers are found, stop the process.
Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
Repeat this process as long as you keep finding two adjacent non-coprime numbers.
Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in any arbitrary order will lead to the same result.

The test cases are generated such that the values in the final array are less than or equal to 108.

Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.

 

Example 1:

Input: nums = [6,4,3,2,7,6,2]
Output: [12,7,6]
Explanation: 
- (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
- (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
- (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
- (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [12,7,6].
Note that there are other ways to obtain the same resultant array.
Example 2:

Input: nums = [2,2,1,1,3,3,3]
Output: [2,1,1,3]
Explanation: 
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3,3].
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3].
- (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [2,1,1,3].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [2,1,1,3].
Note that there are other ways to obtain the same resultant array.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
The test cases are generated such that the values in the final array are less than or equal to 108.
*/

/*
Approach:
1. Traverse the array left to right while maintaining a stack-like vector `result`.
2. For each number `num`:
   - While the last element in `result` is not coprime with `num`:
     - Compute gcd(prev, num).
     - Merge them into a single number by taking their LCM.
     - Replace `num` with this LCM and pop the previous element.
   - Push the merged number back into `result`.
3. At the end, `result` contains the required array after merging.

Intuition:
- If two consecutive numbers share a common divisor > 1, they must be merged into their LCM.
- This merging may propagate backwards (hence the loop while `result` is not empty).
- Using gcd and LCM ensures correctness while avoiding overflow.

Time Complexity:
- O(n * log(max(nums[i]))), since gcd calculation takes log(max(nums[i])) time.
- Each number is pushed and popped at most once from `result`.

Space Complexity:
- O(n) in the worst case, for the `result` vector.

*/

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result; // acts like a stack

        // Process array from left to right
        for (int num : nums) {
            // Keep merging while the last number in result is not coprime with num
            while (!result.empty()) {
                int prev = result.back();
                int curr = num;

                int GCD = gcd(prev, curr);
                if (GCD == 1) {
                    break; // They are coprime, stop merging
                }

                result.pop_back(); // Remove the last element
                // Compute LCM safely
                num = prev / GCD * curr; 
            }
            // Push the final merged number back
            result.push_back(num);
        }

        return result;
    }
};
