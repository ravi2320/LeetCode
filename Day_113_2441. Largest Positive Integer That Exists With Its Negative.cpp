/*
2441. Largest Positive Integer That Exists With Its Negative
Solved
Easy
Topics
Companies
Hint
Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.

 

Example 1:

Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.
Example 2:

Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
Example 3:

Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.
 

Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
nums[i] != 0
*/

// Intuition:
// This function finds the maximum value 'k' from the given array such that '-k' also exists in the array.
// It first sorts the array in non-decreasing order.
// Then, it uses a two-pointer approach where one pointer 'i' starts from the beginning of the array,
// and another pointer 'j' starts from the end of the array.
// The algorithm iterates until 'i' is less than 'j' and compares the sum of elements at 'i' and 'j' with zero.
// If the sum is zero, it returns the absolute value of the element at 'j' as the maximum value 'k'.
// If the sum is greater than zero, it decrements 'j' to reduce the sum.
// If the sum is less than zero, it increments 'i' to increase the sum.

// Time Complexity: O(N log N)
// - Sorting the array takes O(N log N) time.
// - The two-pointer approach takes O(N) time.

// Space Complexity: O(1)
// - The algorithm uses constant extra space.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array in non-decreasing order
        int i = 0, j = nums.size() - 1; // Initialize pointers i and j
        
        // Iterate until i < j
        while (i < j) {
            if (nums[i] == -nums[j]) // If the sum of elements at i and j is zero
                return nums[j]; // Return the absolute value of the element at j as the maximum value 'k'
            else if (nums[i] > -nums[j]) // If the sum is greater than zero
                j--; // Decrement j to reduce the sum
            else if (nums[i] < -nums[j]) // If the sum is less than zero
                i++; // Increment i to increase the sum
        }
        return -1; // If no such 'k' exists, return -1
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, -1, -2, -3, 4, 5};
    int result = obj.findMaxK(nums);
    cout << "Maximum value k: " << result << endl; // Output: Maximum value k: 3
    return 0;
}


// Intuition:
// This function finds the maximum value 'k' from the given array such that '-k' also exists in the array.
// It uses an unordered set to store the elements encountered so far.
// It iterates through the array, and for each element 'nums[i]', it checks if '-nums[i]' exists in the set.
// If it does, it updates the result 'res' with the maximum of its current value and the absolute value of 'nums[i]'.
// Finally, it returns the maximum value 'res' found during the iteration.

// Time Complexity: O(N)
// - 'N' is the number of elements in the input array.
// - The algorithm iterates through the array once.

// Space Complexity: O(N)
// - The unordered set can contain up to 'N' elements in the worst case.

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st; // Create an unordered set to store elements encountered so far
        int res = -1; // Initialize the result 'res' to -1
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(-nums[i]) != st.end()) { // Check if '-nums[i]' exists in the set
                res = max(res, abs(nums[i])); // Update 'res' with the maximum of its current value and the absolute value of 'nums[i]'
            }
            st.insert(nums[i]); // Insert 'nums[i]' into the set
        }
        
        return res; // Return the maximum value 'res'
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, -1, -2, -3, 4, 5};
    int result = obj.findMaxK(nums);
    cout << "Maximum value k: " << result << endl; // Output: Maximum value k: 3
    return 0;
}