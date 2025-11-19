/*
2154. Keep Multiplying Found Values by Two

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.

You then do the following steps:

If original is found in nums, multiply it by two (i.e., set original = 2 * original).
Otherwise, stop the process.
Repeat this process with the new number as long as you keep finding the number.
Return the final value of original.

 

Example 1:

Input: nums = [5,3,6,1,12], original = 3
Output: 24
Explanation: 
- 3 is found in nums. 3 is multiplied by 2 to obtain 6.
- 6 is found in nums. 6 is multiplied by 2 to obtain 12.
- 12 is found in nums. 12 is multiplied by 2 to obtain 24.
- 24 is not found in nums. Thus, 24 is returned.
Example 2:

Input: nums = [2,7,9], original = 4
Output: 4
Explanation:
- 4 is not found in nums. Thus, 4 is returned.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i], original <= 1000
*/

// Intuition:
// The goal is to start with the number 'original' and repeatedly multiply it by 2 
// as long as it exists in the input array 'nums'. This is done by checking if 'original' 
// exists in the set of numbers derived from 'nums'. Once 'original' is not found in the set, 
// we return it as the final result.
//
// Approach:
// 1. Convert the given vector 'nums' into an unordered set for O(1) average time complexity 
//    when checking if a number exists.
// 2. While 'original' exists in the set, multiply 'original' by 2.
// 3. Once 'original' is no longer found in the set, return it as the result.
//
// Time Complexity:
// O(n), where n is the size of the input vector 'nums'. We iterate over the array once to 
// build the set, and each membership check (st.count(original)) takes O(1) on average.
//
// Space Complexity:
// O(n), where n is the size of the input vector 'nums', as we are storing all elements of 'nums' 
// in an unordered set.

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        // Create an unordered set from the input vector 'nums' for quick look-up
        unordered_set<int> st(nums.begin(), nums.end());

        // Keep doubling 'original' as long as it exists in the set
        while(st.count(original)) {
            original *= 2;  // Double the value of 'original'
        }

        // Return the final value of 'original' after exiting the loop
        return original;
    }
};
