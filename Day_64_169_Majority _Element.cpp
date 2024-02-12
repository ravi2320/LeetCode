/*
169. Majority Element
Solved
Easy
Topics
Companies
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > n/2)
                return nums[i];
        }
        return 0;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0, cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(cnt == 0){
                num = nums[i];
                cnt++;
            }
            else if(num == nums[i])
                cnt++;
            else
                cnt--;
        }
        return num;
    }
};