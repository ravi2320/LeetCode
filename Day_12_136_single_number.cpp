/*

136. Single Number
Solved
Easy
Topics
Companies
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.




class Solution {
public:
    int singleNumber(vector<int>& nums) {

       unordered_map<int, int> counter;
       for(int i=0; i<nums.size(); i++)
       {
           counter[nums[i]]++;
       } 
       for(int i=0; i<nums.size(); i++)
       {
           if(counter[nums[i]] == 1)
            return nums[i];
       }
       return -1;
    }
};

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;
        for(int i=0; i<nums.size(); i++)
            ans = ans ^ nums[i];  //ans = ans XOR nums[i]
        return ans;
    }
};