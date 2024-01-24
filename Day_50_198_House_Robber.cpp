/*
198. House Robber
Solved
Medium
Topics
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

//Recursion with memorization
class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp){
        if(i == 0) return nums[i];
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + f(i-2, nums, dp);
        int notPick = 0 + f(i-1, nums, dp);

        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
    }
};


//tabulation with memoization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            
            int pick = nums[i] + dp[i-2]; 
            int notpick = 0 + dp[i-1];

            dp[i] = max(pick, notpick);
        }
        return dp[n-1];
    }
};

//tabulation with space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int prev = nums[0];
        int prev2 = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            
            int pick = nums[i] + prev; 
            int notpick = prev2;
            int curr = max(pick, notpick);

            prev = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};