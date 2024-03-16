/*
238. Product of Array Except Self
Solved
Medium
Topics
Companies
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

//Approach 1: Brute Force TC-O(n^2) SC-O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int ans = 1;
            for(int j=0; j<n; j++){
                if(i == j)
                    continue;
                ans *= nums[j];
            }
            res.push_back(ans);
        }
        return res;
    }
};

//Approach 2: By Division  TC-O(n) SC-O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int cnt = 0, ans = 1;
        for(int i=0; i < n; i++){
            if(nums[i] == 0)
                cnt++;
            else
                ans *= nums[i];
            
            if(cnt > 1)
                return res;
        }
        
        for(int i=0; i<n; i++){
            if(cnt > 0 && nums[i])
                continue;
            else if(cnt > 0 && nums[i] == 0)
                res[i] = ans;
            else
                res[i] = ans/nums[i];
        }
        return res;
    }
};

//Approach 3: Without Division but With Extra Space, TC-O(n), SC-O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = 1, right[n-1] = 1;
        for(int i=1; i<n; i++){
            left[i] = nums[i-1] * left[i-1];
        }

        for(int i=n-2; i >= 0; i--){
            right[i] = nums[i+1] * right[i+1];
        }

        vector<int> res(n);
        for(int i=0; i<n; i++){
            res[i] = left[i] * right[i];
        }
        return res;
    }
};

//Approach 4: Division Without Extra Space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        res[0] = 1;
        for(int i=1; i<n; i++){
            res[i] = nums[i-1] * res[i-1];
        }
        int rightProduct = 1;
        for(int i=n-1; i >= 0; i--){
            res[i] = res[i] * rightProduct;
            rightProduct *= nums[i];
        }
        return res;
    }
};