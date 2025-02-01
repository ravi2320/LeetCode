/*
3151. Special Array I
Solved
Easy
Topics
Companies
Hint
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

 

Example 1:

Input: nums = [1]

Output: true

Explanation:

There is only one element. So the answer is true.

Example 2:

Input: nums = [2,1,4]

Output: true

Explanation:

There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

Example 3:

Input: nums = [4,3,1,6]

Output: false

Explanation:

nums[1] and nums[2] are both odd. So the answer is false.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

/*
Approach:
1. A special array is defined as one where **adjacent elements alternate in parity** (even, odd, even, odd... or odd, even, odd, even...).
2. We iterate through the array starting from the second element.
3. For each pair of adjacent elements `(nums[i-1], nums[i])`, we check if their parities differ:
   - If they do, continue.
   - If they don't, return false immediately.
4. If we complete the iteration without finding adjacent elements with the same parity, the array is special.

Intuition:
- By comparing the **parity of consecutive elements**, we can quickly determine if the array alternates correctly.

Time Complexity:
- **O(N)** where N is the length of the array (one pass through the array).

Space Complexity:
- **O(1)** since we only use a few extra variables for tracking parity.
*/

class Solution {
public:
    // Function to check if the array is special (alternating parity)
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        
        // Iterate through the array to check parity alternation
        for (int i = 1; i < n; i++) {
            // If consecutive elements have the same parity, return false
            if ((nums[i - 1] % 2 == nums[i] % 2)) {
                return false;
            }
        }
        
        // If no parity violations found, array is special
        return true;
    }
};
