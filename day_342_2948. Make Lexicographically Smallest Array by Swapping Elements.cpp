/*
2948. Make Lexicographically Smallest Array by Swapping Elements
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed array of positive integers nums and a positive integer limit.

In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

 

Example 1:

Input: nums = [1,5,3,9,8], limit = 2
Output: [1,3,5,8,9]
Explanation: Apply the operation 2 times:
- Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
- Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
We cannot obtain a lexicographically smaller array by applying any more operations.
Note that it may be possible to get the same result by doing different operations.
Example 2:

Input: nums = [1,7,6,18,2,1], limit = 3
Output: [1,6,7,18,1,2]
Explanation: Apply the operation 3 times:
- Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
- Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
- Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
We cannot obtain a lexicographically smaller array by applying any more operations.
Example 3:

Input: nums = [1,7,28,19,10], limit = 3
Output: [1,7,28,19,10]
Explanation: [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= limit <= 109
*/

/*
Approach:
1. Iterate through the array.
2. For each element, find the smallest element within the limit range that is lexicographically smaller and swap it.
3. Continue until the entire array is processed.

Time Complexity: O(n^2) - Nested iteration to check within the limit.
Space Complexity: O(1) - In-place swapping.
*/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Iterate through each element
        for (int i = 0; i < n; i++) {
            int minIdx = i;

            // Find the smallest valid element within the range
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= limit && nums[j] < nums[minIdx]) {
                    minIdx = j;
                }
            }

            // Swap if a smaller value is found
            if (minIdx != i) {
                swap(nums[i], nums[minIdx]);
            }
        }

        return nums;
    }
};

/*
Approach:
1. First, sort the array to determine groups of numbers that can be swapped while maintaining the `limit` constraint.
2. Use a `groupToNum` map to assign a group ID to each number based on its value and the `limit`.
3. Use a `groupToList` map to keep track of the sorted numbers within each group.
4. Iterate over the original array and replace each number with the smallest number from its group using `groupToList`.

Intuition:
- Sorting helps to identify clusters of numbers that can be swapped to achieve a lexicographically smaller array while adhering to the `limit`.
- Grouping ensures that only numbers within the valid range (`limit`) of each other are considered for swaps.

Time Complexity:
- Sorting the array: O(n log n).
- Assigning groups and iterating over the original array: O(n).
- Overall: O(n log n).

Space Complexity:
- Additional space for `groupToNum` and `groupToList`: O(n).
- Overall: O(n).
*/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Create a copy of the array and sort it
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        // Group assignment
        int groupNum = 0;
        unordered_map<int, int> groupToNum; // Maps number to its group
        groupToNum[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToList; // Maps group to list of numbers in sorted order
        groupToList[groupNum].push_back(vec[0]);

        // Assign group IDs based on the limit constraint
        for (int i = 1; i < n; i++) {
            if (vec[i] - vec[i - 1] > limit) {
                groupNum++;
            }
            groupToNum[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }

        // Create the result array
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int group = groupToNum[nums[i]]; // Get the group ID of the current number

            // Replace the number with the smallest number in its group
            res[i] = *groupToList[group].begin();
            groupToList[group].pop_front(); // Remove the used number from the group
        }

        return res;
    }
};