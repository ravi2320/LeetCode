/*
2530. Maximal Score After Applying K Operations
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

In one operation:

choose an index i such that 0 <= i < nums.length,
increase your score by nums[i], and
replace nums[i] with ceil(nums[i] / 3).
Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.

 

Example 1:

Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
Example 2:

Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation: You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.
 

Constraints:

1 <= nums.length, k <= 105
1 <= nums[i] <= 109
*/


/*
Approach:
1. Use a max-heap (priority queue) to get the maximum element efficiently.
2. For each of the k steps:
   a. Pop the maximum element.
   b. Add the maximum element to the result.
   c. Replace the maximum element with ceil((maxElement + 2) / 3) and push it back into the heap.
3. Return the accumulated result after k operations.

Time Complexity: O(k log n), where k is the number of operations and n is the number of elements in the array.
Space Complexity: O(n), where n is the number of elements in the input array.
*/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;  // Variable to store the result (sum of maximum elements)
        priority_queue<int> pq;  // Max-heap to store elements

        // Push all elements of the array into the max-heap
        for(int &x : nums) {
            pq.push(x);
        }

        // Perform k operations
        while(!pq.empty() && k--) {
            int maxEle = pq.top();  // Get the maximum element
            pq.pop();  // Remove the maximum element from the heap

            res += maxEle;  // Add the maximum element to the result

            // Push back ceil((maxEle + 2) / 3) into the heap
            pq.push((maxEle + 2) / 3);  // Ensure proper division with floating-point result
        }

        return res;  // Return the final result after k operations
    }
};
