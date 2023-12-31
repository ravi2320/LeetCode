/*
961. N-Repeated Element in Size 2N Array
Solved
Easy
Topics
Companies
You are given an integer array nums with the following properties:

nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.

Explaination:
In our example: nums = [2, 4, 5, 3, 2, 1]

The loop iterates through each element in nums.
For the first iteration, i = 2, and the hash map is updated as follows:
hash[2] becomes 1.
For the second iteration, i = 4, and the hash map is updated:
hash[4] becomes 1.
For the third iteration, i = 5, and the hash map is updated:
hash[5] becomes 1.
For the fourth iteration, i = 3, and the hash map is updated:
hash[3] becomes 1.
For the fifth iteration, i = 2, and the hash map is checked:
hash[2] is already 1, so the function returns 2 because 2 is the element that is repeated n times. 

Example 1:

Input: nums = [1,2,3,3]
Output: 3
Example 2:

Input: nums = [2,1,2,5,3,2]
Output: 2
Example 3:

Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
 

Constraints:

2 <= n <= 5000
nums.length == 2 * n
0 <= nums[i] <= 104
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int i:nums)
        {
            if(hash[i] == 1)
                return i;
            else
                hash[i] = 1;
        }
        return 0;
    }
};