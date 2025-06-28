/*
2099. Find Subsequence of Length K With the Largest Sum

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
 

Constraints:

1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length
*/

/*
Approach:
We are given an array `nums` and an integer `k`. The task is to find the subsequence of length `k` 
which has the **maximum sum** while preserving the **original order** from the array.

This implementation uses a brute-force method:
1. For `k` iterations, select the maximum available element (not already chosen) from `nums`.
2. Track the selected indices using a set to avoid repeats.
3. After collecting `k` indices, use them to form the final result vector.

Intuition:
- The algorithm mimics greedy selection by picking the maximum element repeatedly,
  but it does not guarantee preservation of relative order (since `set` sorts indices).
  Hence, the **order may be broken**, which is incorrect for this problem.

Time Complexity:
- O(k * n): For each of the k elements, we traverse the array of size n to find the maximum.
- O(k log k): For inserting and iterating through the set of indices.

Space Complexity:
- O(k): For storing the selected indices.

⚠️ Note:
This approach **fails to preserve the order of elements** correctly in all cases because 
`set` sorts indices, not preserving their insertion sequence. A better approach is 
to store value-index pairs and sort them manually.

*/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;  // To store selected indices (sorted automatically)

        for (int sel = 0; sel < k; sel++) {
            int maxIdx = INT_MIN;

            // Find the max value not already selected
            for (int i = 0; i < n; i++) {
                if (!st.count(i) && 
                    (maxIdx == INT_MIN || nums[i] > nums[maxIdx])) {
                    maxIdx = i;
                }
            }

            if (maxIdx != INT_MIN) {
                st.insert(maxIdx);
            }
        }

        // Build result using indices (⚠️ order may not be preserved!)
        vector<int> res;
        for (int idx : st) {
            res.push_back(nums[idx]);
        }

        return res;
    }
};


/*
Approach:
We are given an array `nums` and an integer `k`. The goal is to return the subsequence of length `k` that has the 
**maximum sum** and also **preserves the order** from the original array.

Strategy:
1. Use a min-heap (priority_queue with greater comparator) to maintain the top `k` elements with the largest values.
2. Store both the value and the original index in the heap to retain the order.
3. Once we have the top `k` largest elements, sort them by their original indices to maintain relative order.
4. Extract the values from the sorted pairs to form the result.

Intuition:
- The priority queue helps efficiently keep track of the top `k` largest elements in O(n log k).
- Sorting by index ensures the original order is preserved in the result.

Time Complexity:
- O(n log k): for inserting into priority queue.
- O(k log k): for sorting the final selected elements by index.

Space Complexity:
- O(k): for heap and result storage.

*/

class Solution {
    typedef pair<int, int> P; // Pair of <value, original_index>
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        // Min-heap to keep the top k largest elements
        priority_queue<P, vector<P>, greater<P>> pq;

        // Push all elements into the heap, but only keep the k largest
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});

            // Remove the smallest if size exceeds k
            if (pq.size() > k)
                pq.pop();
        }

        // Extract the top k elements and store in a vector
        vector<pair<int, int>> sortedArray;
        while (!pq.empty()) {
            sortedArray.push_back(pq.top());
            pq.pop();
        }

        // Sort based on original index to maintain order
        sort(sortedArray.begin(), sortedArray.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Extract values from the sorted array to form the result
        vector<int> res;
        for (auto &p : sortedArray) {
            res.push_back(p.first);
        }

        return res;
    }
};
