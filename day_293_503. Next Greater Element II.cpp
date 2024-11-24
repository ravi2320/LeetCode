/*
503. Next Greater Element II
Solved
Medium
Topics
Companies
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109
*/

/*
Approach:
1. The problem involves finding the next greater element for each element in a circular array. 
   If no greater element exists, return -1 for that position.
2. Since the array is circular, each element can potentially be compared with elements before it in the list (if treated linearly).
3. We use a stack to keep track of potential "next greater" elements.
   - Iterate the array from the end to the beginning (two passes to handle circular nature).
   - Use the stack to keep elements in decreasing order. The top of the stack will be the next greater element.
   - If an element from the array has a greater element in the stack, record it in the result.
   
Steps:
1. Use a loop to simulate two passes over the array by iterating from index `2n-1` to `0`.
2. Use the stack to manage elements and find the next greater element efficiently.
3. If the index is within the array bounds (`i < n`), store the result; otherwise, continue to process.
4. Push elements into the stack as you encounter them to maintain candidates for the "next greater" elements.

Time Complexity:
- O(n) — each element is pushed and popped from the stack at most once.

Space Complexity:
- O(n) — for storing the result and the stack.

*/

class Solution {
public:
    // Function to find the next greater element in a circular array
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1); // Initialize the result vector with -1
        stack<int> st;          // Stack to store indices of elements

        // Loop through the array twice for circular behavior
        for(int i = 2 * n - 1; i >= 0; i--) {
            // Maintain elements in the stack that are greater than the current element
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            } 

            // Store the next greater element if found
            if(i < n && !st.empty()) {
                res[i] = st.top();
            }

            // Push the current element to the stack
            st.push(nums[i % n]);
        }

        return res;
    }
};