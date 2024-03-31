/*
189. Rotate Array
Solved
Medium
Topics
Companies
Hint
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

/*
Intuition:

We first check if the rotation amount k is 0 or a multiple of the array size n. In these cases, no rotation is needed, so we return early.
Then, we reduce k to be within the range [0, n) to handle cases where k may be greater than the array size.
We create a temporary vector to store the last k elements of the array, which will be rotated to the beginning.
We copy the last k elements of nums to temp in reverse order.
Finally, we copy the elements from temp back to the beginning of nums.
Time Complexity:

The time complexity of this approach is O(n) because we iterate over the array twice: once to copy the last k elements to temp, and once to copy them back to the beginning of nums.
Space Complexity:

The space complexity is O(k) because we use a temporary vector temp to store the last k elements of the array.

*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // If k is 0 or a multiple of n, no rotation is needed
        if (k == 0 || k % n == 0) return;

        // Reduce k to be within the range [0, n)
        k = k % n;

        // Create a temporary vector to store the last k elements
        vector<int> temp(k);
        
        // Copy the last k elements of nums to temp in reverse order
        for (int i = 1; i <= n; i++) {
            if (i <= k)
                temp[k - i] = nums[n - i];
            else
                nums[n - i + k] = nums[n - i];
        }
        
        // Copy the elements from temp back to the beginning of nums
        for (int i = 0; i < k; i++)
            nums[i] = temp[i];
    }
};


/*
Intuition:
- We first check if the array is empty or if k is a multiple of the array size. In these cases, no rotation is needed, so we return early.
- We reduce k to be within the range [0, n) to handle cases where k may be greater than the array size.
- We create a temporary vector to store the last k elements of the array, which will be rotated to the beginning.
- We then erase the last k elements from nums using the erase function.
- Finally, we insert the elements from the temporary vector back to the beginning of nums using the insert function.

Time Complexity:
- The time complexity of this approach is O(n) because we perform one erase operation and one insert operation, each of which takes O(n) time.

Space Complexity:
- The space complexity is O(k) because we use a temporary vector to store the last k elements of the array.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // Return early if the array is empty or if k is a multiple of n
        if (n == 0 || k % n == 0)
            return;

        // Reduce k to be within the range [0, n)
        k = k % n;

        // Create a temporary vector to store the last k elements
        vector<int> temp(nums.begin() + n - k, nums.end());

        // Erase the last k elements from nums
        nums.erase(nums.begin() + n - k, nums.end());

        // Insert the elements from temp back to the beginning of nums
        nums.insert(nums.begin(), temp.begin(), temp.end());
    }
};


/*
Intuition:
- To rotate an array to the right by k positions, we can reverse the entire array first.
- Then, we reverse the first k elements of the array.
- Finally, we reverse the remaining elements of the array.
- This process effectively rotates the array to the right by k positions.

Time Complexity: O(n)
- Reversing the entire array takes O(n) time.
- Reversing the first k elements and the remaining elements each takes O(k/2) = O(k) time.
- Thus, the overall time complexity is O(n + k + k) = O(n).

Space Complexity: O(1)
- The algorithm operates in-place and does not require any additional space, except for a constant amount of extra space used for variables.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        // Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};