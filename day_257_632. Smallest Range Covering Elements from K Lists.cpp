/*
632. Smallest Range Covering Elements from K Lists
Solved
Hard
Topics
Companies
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.
*/

/*
Approach:
1. Use a vector of indices to track the current element in each list.
2. Find the current minimum and maximum element across all lists using the indices.
3. Update the smallest range if the difference between the current maximum and minimum is smaller.
4. Move the index for the list that contains the minimum element and repeat until one list is fully traversed.

Time Complexity: O(n * k), where n is the average length of the lists and k is the number of lists.
Space Complexity: O(k), for storing the current index of each list.
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(); // Number of lists

        vector<int> range = {-100000, 100000}; // Initial range, set to a very large range
        vector<int> vec(k, 0); // Tracks the current index in each list

        // Loop until one list is fully traversed
        while (true) {
            int minEle = INT_MAX;
            int maxEle = INT_MIN;
            int minEleIdx = 0; // Index of the list that contains the minimum element

            // Find the current minimum and maximum elements across the lists
            for (int i = 0; i < k; i++) {
                int eleIdx = vec[i];
                int element = nums[i][eleIdx];

                if (element < minEle) {
                    minEle = element;
                    minEleIdx = i;
                }

                maxEle = max(maxEle, element);
            }

            // Update the range if the new range is smaller
            if (maxEle - minEle < range[1] - range[0]) {
                range[0] = minEle;
                range[1] = maxEle;
            }

            // Move the index for the list that contains the minimum element
            vec[minEleIdx]++;

            // Terminate if any of the lists are fully traversed
            if (vec[minEleIdx] >= nums[minEleIdx].size()) {
                break;
            }
        }

        return range;
    }
};


/*
Approach:
1. Use a min-heap (priority queue) to always get the minimum element across the lists.
2. Track the maximum element encountered so far to compute the range.
3. Push the next element from the list that had the minimum element into the heap.
4. Continue until one list is exhausted.

Time Complexity: O(n * log k), where n is the average length of the lists and k is the number of lists.
Space Complexity: O(k), for storing the heap.
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(); // Number of lists

        // Min-heap to store {element, list index, element index}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Range initialized to a large value
        vector<int> range = {-1000000, 1000000};
        int maxEle = INT_MIN; // Track the maximum element across all lists

        // Initialize the heap with the first element of each list
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0}); // {value, list index, element index}
            maxEle = max(maxEle, nums[i][0]); // Update maxEle with the largest first element
        }

        // Continue processing until we exhaust one of the lists
        while(!pq.empty()) {
            int minEle = pq.top()[0]; // Current minimum element
            int list = pq.top()[1];   // The list from which the element came
            int idx = pq.top()[2];    // Index of the element in the list
            pq.pop(); // Remove the smallest element from the heap

            // Update the range if the new range is smaller
            if(maxEle - minEle < range[1] - range[0]) {
                range[1] = maxEle;
                range[0] = minEle;
            }

            // If the current list is exhausted, break the loop
            if(idx + 1 >= nums[list].size()) {
                break;
            }

            // Add the next element from the same list to the heap
            pq.push({nums[list][idx + 1], list, idx + 1});
            // Update the maxEle with the new element
            maxEle = max(maxEle, nums[list][idx + 1]);
        }

        return range;
    }
};
