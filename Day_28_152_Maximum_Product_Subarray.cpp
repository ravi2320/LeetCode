/*
152. Maximum Product Subarray
Solved
Medium
Topics
Companies
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/
class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        //base case
        if(start > end){
            return INT_MIN;
        }
        if(start == end){
            return nums[start];
        }

        int mid = start + (end-start)/2;
        int leftProduct = solve(nums, start, mid);
        int rightProduct = solve(nums, mid+1, end);

        int leftMin = 0, leftMax = 0, rightMin = 0, rightMax = 0;
        int product = 1;
        for(int i = mid; i >= start; i--){
            product *= nums[i];
            if(product > leftMax){
                leftMax = product;
            }
            if(product < leftMin){
                leftMin = product;
            }
        }

        product = 1;
        for(int i = mid+1; i <= end; i++){
            product *= nums[i];
            if(product > rightMax){
                rightMax = product;
            }
            if(product < rightMin){
                rightMin = product;
            }
        }
        int crossBorderProduct = max(leftMin * rightMin, leftMax * rightMax);
        return max(crossBorderProduct, max(leftProduct, rightProduct));
    }


    int maxProduct(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        return solve(nums, start, end);
    }
};


//Optimal Solution
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixProduct = 1;
        int suffixProduct = 1;

        int n = nums.size();
        
        int ans = -1e9;
        for(int i=0;i<nums.size();i++){
            if(prefixProduct == 0){
               prefixProduct = 1;
            }
            prefixProduct *= nums[i]; 

            if(suffixProduct == 0){
                suffixProduct = 1;
            }
            suffixProduct *= nums[n-i-1];

            ans = max(ans,max(prefixProduct,suffixProduct));
        }
        return ans;
    }
};