/*
3191. Minimum Operations to Make Binary Array Elements Equal to One I
Solved
Medium
Topics
Companies
Hint
You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

 

Example 1:

Input: nums = [0,1,1,1,0,0]

Output: 3

Explanation:
We can do the following operations:

Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
Example 2:

Input: nums = [0,1,1,1]

Output: -1

Explanation:
It is impossible to make all elements equal to 1.

 

Constraints:

3 <= nums.length <= 105
0 <= nums[i] <= 1
*/

/*
Approach:
---------
- Traverse the array from left to right.
- For each element:
    - If nums[i] == 1, it's already 1, continue.
    - If nums[i] == 0:
        -> Flip current element and next two elements using XOR (^= 1).
        -> Increment count of operations.
- After processing, check if last two elements are both 1:
    - If yes, return total operations count.
    - Else, return -1 (cannot make all elements 1).

Intuition:
----------
- We flip as early as possible when a 0 is encountered.
- Each flip affects current and next two elements, so no need to revisit flipped elements.
- The greedy approach works because locally fixing 0 at earliest opportunity gives optimal result.

Time Complexity: O(n)
---------------------
- Single pass through the array.

Space Complexity: O(1)
---------------------
- Only constant space used.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0; // Operation counter
        
        // Traverse up to n-2, as we flip i, i+1, i+2
        for(int i = 0; i < n - 2; i++) {
            if(nums[i] == 1) {
                continue; // Already 1, skip
            } else {
                // Flip nums[i], nums[i+1], nums[i+2]
                nums[i]   ^= 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                
                cnt++; // Increment operation count
            }
        }
        
        // Check if last two elements are both 1
        if(nums[n-2] == 1 && nums[n-1] == 1) {
            return cnt;
        }
        
        // If not possible
        return -1;
    }
};
