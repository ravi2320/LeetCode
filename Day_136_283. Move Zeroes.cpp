/*
283. Move Zeroes
Solved
Easy
Topics
Companies
Hint
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
*/

/*
Intuition:
- The task is to move all zeros in the array to the end while maintaining the relative order of the non-zero elements.
- The approach involves iterating through the array, collecting non-zero elements in a temporary vector, and then placing these non-zero elements back in the original array, followed by filling the remaining positions with zeros.

Approach:
1. Create a temporary vector to store the non-zero elements.
2. Iterate through the input array and append non-zero elements to the temporary vector.
3. Copy the elements from the temporary vector back to the input array.
4. Fill the remaining positions in the input array with zeros.

Time Complexity: O(n)
- The algorithm performs two passes through the array, making it linear in time complexity.

Space Complexity: O(n)
- The algorithm uses additional space for the temporary vector, which can be as large as the input array.

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();

        // Collect all non-zero elements
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0)
                temp.push_back(nums[i]);
        }

        // Place the non-zero elements back in the original array
        for(int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }

        // Fill the remaining positions with zeros
        for(int i = temp.size(); i < n; i++) {
            nums[i] = 0;
        }
    }
};


/*
Intuition:
- This approach minimizes the number of swaps by using two pointers.
- The first pointer, 'j', is used to locate the position where the first zero is found.
- The second pointer, 'i', iterates through the array to find non-zero elements after the first zero position ('j').
- Whenever a non-zero element is found, it is swapped with the zero at position 'j', and 'j' is incremented.

Approach:
1. Initialize 'j' to -1 to indicate that no zero has been found yet.
2. Iterate through the array to find the first zero position ('j').
3. If a zero is found, set 'j' to the current index and break out of the loop.
4. If 'j' is not -1 (i.e., if a zero was found), iterate through the array from 'j+1' to the end.
5. Whenever a non-zero element is encountered at index 'i', swap it with the zero at index 'j' and increment 'j'.
6. This process ensures that all non-zero elements after the first zero are moved to the left of the array, while preserving their relative order.

Time Complexity: O(n)
- The algorithm performs a single pass through the array, making it linear in time complexity.

Space Complexity: O(1)
- The algorithm operates in constant space, as it performs all operations in-place without using any extra space.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1; // Pointer to locate the first zero position

        // Find the first zero position
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }

        // If a zero is found, move non-zero elements to the left of the array
        if(j != -1) {
            for(int i = j + 1; i < n; i++) {
                // If a non-zero element is found, swap it with the zero at position 'j'
                if(nums[i] != 0) {
                    swap(nums[i], nums[j]);
                    j++; // Increment 'j' to maintain the position of the next zero
                }
            }
        }
    }
};
