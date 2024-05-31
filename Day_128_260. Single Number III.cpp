/*
260. Single Number III
Solved
Medium
Topics
Companies
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/

// Intuition:
// - The problem requires finding two numbers in the array that appear only once, while all other numbers appear exactly twice.
// - Using XOR properties, we can find these two unique numbers efficiently.
// - XOR of the entire array gives us the XOR of the two unique numbers, say `a` and `b`.
// - Using a bit mask, we can separate the numbers into two groups based on one of the differing bits between `a` and `b`.
// - XOR within each group will isolate the unique numbers `a` and `b`.

// Time Complexity: O(N)
// - We iterate through the array a constant number of times (three passes in total), leading to a linear time complexity.

// Space Complexity: O(1)
// - We use a constant amount of extra space.

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        // Step 1: XOR all numbers to get xor_r = a ^ b (where a and b are the unique numbers)
        long long xor_r = 0;
        for(int &num : nums){
            xor_r ^= num;
        }

        // Step 2: Find a bit that is different between a and b (rightmost set bit)
        int mask = xor_r & (-xor_r);

        // Step 3: Partition the numbers into two groups and XOR each group
        int groupA = 0, groupB = 0;
        for(int &num : nums){
            if(num & mask){
                groupA ^= num;
            }
            else{
                groupB ^= num;
            }
        }

        // Return the two unique numbers
        return {groupA, groupB};
    }
};
