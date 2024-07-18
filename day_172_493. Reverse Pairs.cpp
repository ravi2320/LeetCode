/*
493. Reverse Pairs
Solved
Hard
Topics
Companies
Hint
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

/**
 * Intuition:
 * - This problem requires counting the number of important reverse pairs in the array. A reverse pair is defined as
 *   nums[i] > 2 * nums[j] where i < j.
 * - We can use a modified merge sort algorithm to efficiently count the reverse pairs while sorting the array.
 * - The merge sort helps by dividing the array into smaller subarrays, counting the reverse pairs in the subarrays, 
 *   and merging the results.
 * 
 * Time Complexity:
 * - The time complexity is O(n log n), where n is the size of the array. This is because merge sort takes O(n log n)
 *   time and the pair counting within each merge step takes O(n) time.
 *
 * Space Complexity:
 * - The space complexity is O(n), where n is the size of the array. This is due to the temporary array used for merging.
 */

class Solution {
public:
    // Function to merge two sorted subarrays and sort them
    void merge(vector<int> &nums, int low, int mid, int high){
        vector<int> temp; // Temporary array for merging
        int left = low;
        int right = mid + 1;

        // Merge the two sorted subarrays
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Copy the remaining elements from the left subarray, if any
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        // Copy the remaining elements from the right subarray, if any
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        // Copy the merged elements back to the original array
        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }

    // Function to count important reverse pairs in the subarrays
    int countPairs(vector<int> &nums, int low, int mid, int high){
        int right = mid + 1;
        int cnt = 0;

        // Count the important reverse pairs
        for(int i = low; i <= mid; i++){
            while(right <= high && nums[i] > 2L * nums[right]) right++;
            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    // Recursive merge sort function to sort the array and count reverse pairs
    int mergeSort(vector<int>& nums, int low, int high){
        int cnt = 0;

        if(low >= high) return cnt;

        int mid = low + (high - low) / 2;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        
        return cnt;
    }

    // Function to count the number of important reverse pairs in the array
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
