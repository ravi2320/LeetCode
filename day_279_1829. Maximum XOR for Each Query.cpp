/*
1829. Maximum XOR for Each Query
Solved
Medium
Topics
Companies
Hint
You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:

Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
Remove the last element from the current array nums.
Return an array answer, where answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,1,3], maximumBit = 2
Output: [0,3,2,3]
Explanation: The queries are answered as follows:
1st query: nums = [0,1,1,3], k = 0 since 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3.
2nd query: nums = [0,1,1], k = 3 since 0 XOR 1 XOR 1 XOR 3 = 3.
3rd query: nums = [0,1], k = 2 since 0 XOR 1 XOR 2 = 3.
4th query: nums = [0], k = 3 since 0 XOR 3 = 3.
Example 2:

Input: nums = [2,3,4,7], maximumBit = 3
Output: [5,2,6,5]
Explanation: The queries are answered as follows:
1st query: nums = [2,3,4,7], k = 5 since 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7.
2nd query: nums = [2,3,4], k = 2 since 2 XOR 3 XOR 4 XOR 2 = 7.
3rd query: nums = [2,3], k = 6 since 2 XOR 3 XOR 6 = 7.
4th query: nums = [2], k = 5 since 2 XOR 5 = 7.
Example 3:

Input: nums = [0,1,2,2,5,7], maximumBit = 3
Output: [4,3,6,4,6,7]
 

Constraints:

nums.length == n
1 <= n <= 105
1 <= maximumBit <= 20
0 <= nums[i] < 2maximumBit
nums​​​ is sorted in ascending order.
*/

/*
Approach:
1. Calculate the initial XOR of all elements in `nums` to get the XOR of the entire array.
2. Define a `mask` based on `maximumBit`, which will be `(1 << maximumBit) - 1`. This mask is used to flip the bits up to `maximumBit`.
3. For each index in reverse order (from the end of the array to the beginning):
   - Compute the maximum XOR value by XORing `Xor` with the `mask`.
   - Store this value in `res`.
   - Update `Xor` by removing the last element (XORing `Xor` with `nums[i]`).
4. Return `res`, which contains the maximum XOR values in the required order.

Time Complexity: O(n), where n is the size of `nums`, as we process each element once.
Space Complexity: O(n), for storing the result in `res`.

*/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int Xor = 0;
        
        // Calculate the XOR of all elements
        for (int i = 0; i < n; i++) {
            Xor ^= nums[i];
        }

        int mask = (1 << maximumBit) - 1;  // Create a mask to flip bits up to maximumBit
        vector<int> res;
        res.push_back(Xor ^ mask);

        // Process each element in reverse order
        for (int i = n - 1; i >= 1; i--) {
            Xor ^= nums[i];  // Update Xor by removing the current element
            res.push_back(Xor ^ mask);  // Append the XOR result with the mask
        }

        return res;
    }
};
