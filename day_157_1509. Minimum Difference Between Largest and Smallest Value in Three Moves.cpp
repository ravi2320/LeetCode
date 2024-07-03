/*
1509. Minimum Difference Between Largest and Smallest Value in Three Moves
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums.

In one move, you can choose one element of nums and change it to any value.

Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

 

Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
Example 2:

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.
Example 3:

Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

// Intuition:
// The goal is to minimize the difference between the maximum and minimum values of the array 
// after removing exactly three elements. By sorting the array, the smallest possible difference 
// can be achieved by considering different combinations of removing three elements from either end of the array.

// Time Complexity: O(n log n), where n is the number of elements in the array, due to the sorting step.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // If the array has 4 or fewer elements, the minimum difference is 0
        if(n <= 4) 
            return 0;

        // Sort the array to facilitate finding the smallest difference
        sort(nums.begin(), nums.end());

        // Consider removing three elements from either end and calculate the resulting difference
        ans = min(ans, nums[n-4] - nums[0]);
        ans = min(ans, nums[n-1] - nums[3]);
        ans = min(ans, nums[n-2] - nums[2]);
        ans = min(ans, nums[n-3] - nums[1]);

        return ans;
    }
};


// Intuition:
// The goal is to minimize the difference between the maximum and minimum values of the array 
// after removing exactly three elements. By efficiently sorting the necessary parts of the array,
// we can achieve this with better performance in certain cases.

// Time Complexity: O(n), where n is the number of elements in the array, due to the use of 
// partial_sort and nth_element which have linearithmic and linear time complexities respectively.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // If the array has 4 or fewer elements, the minimum difference is 0
        if(n <= 4) 
            return 0;

        // Partially sort the first 4 elements and the last 4 elements
        partial_sort(nums.begin(), nums.begin() + 4, nums.end());

        // Use nth_element to position the last 4 elements correctly
        nth_element(nums.begin() + 4, nums.begin() + n - 4, nums.end());

        // Sort the last 4 elements
        sort(nums.begin() + n - 4, nums.end());

        // Consider removing three elements from either end and calculate the resulting difference
        ans = min(ans, nums[n-4] - nums[0]);
        ans = min(ans, nums[n-1] - nums[3]);
        ans = min(ans, nums[n-2] - nums[2]);
        ans = min(ans, nums[n-3] - nums[1]);

        return ans;
    }
};
