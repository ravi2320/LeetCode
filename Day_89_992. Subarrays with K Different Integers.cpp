/*
992. Subarrays with K Different Integers
Solved
Hard
Topics
Companies
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
*/

/*
Intuition:

We use the sliding window technique to count the number of subarrays with at most k distinct elements.
We maintain a window using two pointers i and j, where i denotes the left boundary of the window and j denotes the right boundary.
As we expand the window to the right, we keep track of the count of distinct elements using a hash map (unordered_map).
Whenever the number of distinct elements in the window exceeds k, we shrink the window from the left until it contains at most k distinct elements.
We count the number of valid subarrays ending at index j and update the total count accordingly.
Finally, we return the count of subarrays with exactly k distinct elements by subtracting the count of subarrays with at most k-1 distinct elements from the count of subarrays with at most k distinct elements.
Time Complexity: O(n)

The sliding window technique involves iterating through the array once with two pointers, resulting in linear time complexity.
Space Complexity: O(n)

We use an unordered_map to store the frequency of elements within the window, which can contain at most n elements in the worst case, resulting in linear space complexity.
*/
class Solution {
public:
    // Function to count subarrays with at most k distinct elements using sliding window
    int slidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, count = 0;
        unordered_map<int, int> mp;

        // Loop through the array using two pointers i and j
        while (j < n) {
            // Expand the window by adding the current element to the map
            mp[nums[j]]++;

            // If the number of distinct elements exceeds k, shrink the window from the left
            while (mp.size() > k) {
                // Decrease the count of nums[i] in the map
                mp[nums[i]]--;

                // If the count becomes 0, remove nums[i] from the map
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);

                // Move the left pointer to the right to shrink the window
                i++;
            }

            // Count the number of valid subarrays ending at index j and update the count
            count += j - i + 1;

            // Move the right pointer to the next element
            j++;
        }

        // Return the total count of subarrays with at most k distinct elements
        return count;
    }

    // Function to count subarrays with exactly k distinct elements
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // The count of subarrays with exactly k distinct elements is
        // equal to the count of subarrays with at most k distinct elements
        // minus the count of subarrays with at most k-1 distinct elements
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};
