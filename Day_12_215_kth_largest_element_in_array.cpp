/*

215. Kth Largest Element in an Array
Solved
Medium
Topics
Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++)
        {
            if(i<k)
                pq.push(-nums[i]);
            else if(-pq.top() < nums[i])
            {
                pq.pop();
                pq.push(-nums[i]);
            }
        }
        return -pq.top();
    }
};

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int size = nums.size();
        return nums[size-k];
    }
};