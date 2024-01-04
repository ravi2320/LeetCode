/*
2870. Minimum Number of Operations to Make Array Empty
Solved
Medium
Topics
Companies
You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

 

Example 1:

Input: nums = [2,3,3,2,2,4,2,3,4]
Output: 4
Explanation: We can apply the following operations to make the array empty:
- Apply the first operation on the elements at indices 0 and 3. The resulting array is nums = [3,3,2,4,2,3,4].
- Apply the first operation on the elements at indices 2 and 4. The resulting array is nums = [3,3,4,3,4].
- Apply the second operation on the elements at indices 0, 1, and 3. The resulting array is nums = [4,4].
- Apply the first operation on the elements at indices 0 and 1. The resulting array is nums = [].
It can be shown that we cannot make the array empty in less than 4 operations.
Example 2:

Input: nums = [2,1,2,2,3,3]
Output: -1
Explanation: It is impossible to empty the array.
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i] <= 106
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int n:nums)
            mp[n]++;
        
        int ans = 0;
        for(auto n : mp){
            if(n.second == 1) 
                return -1;
            int i = n.second%3;
            if(i==0) 
                ans += n.second / 3;
            //If number is 7 then 7 % 3 = 1 and is 7 / 3 = 2 - 1 = 1 + 2 = 3 It is to
            //7 / 3 + 1 = 2 + 1 = 3

            // If count is 8 then 8 % 3 = 2 and answer for 2 is 8 % 3 = 2 + 1 = 3
            // hence for remainder 1 and 2 answer is same so we take it in else case 
            else 
                ans += n.second / 3 + 1;
        }
        return ans;
    }
};