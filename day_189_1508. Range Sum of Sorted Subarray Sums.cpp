/*
1508. Range Sum of Sorted Subarray Sums
Solved
Medium
Topics
Companies
Hint
You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50
 

Constraints:

n == nums.length
1 <= nums.length <= 1000
1 <= nums[i] <= 100
1 <= left <= right <= n * (n + 1) / 2

*/

/*
Intuition:
To find the sum of the range of subarray sums, we first generate all subarray sums, sort them, and then sum the elements in the given range.

Time Complexity:
- Generating all subarray sums takes O(N^2) time.
- Sorting the subarray sums takes O(N^2 log(N^2)) time.
- Summing the range takes O(right - left) time.

Overall, the time complexity is dominated by O(N^2 log(N^2)).

Space Complexity:
- Storing all subarray sums takes O(N^2) space.

*/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> temp;
        int mod = 1e9 + 7;

        // Generate all subarray sums
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                temp.push_back(sum);
            }
        }

        // Sort the subarray sums
        sort(temp.begin(), temp.end());

        // Calculate the sum of elements from 'left' to 'right' in the sorted array
        int res = 0;
        for (int i = left - 1; i < right; i++) {
            res = (res + temp[i]) % mod;
        }

        return res;
    }
};


/*
Intuition:
To efficiently find the sum of subarray sums within a given range without generating all subarray sums, we use a min-heap (priority queue). This allows us to sequentially access the smallest subarray sums in increasing order.

Time Complexity:
- Pushing and popping elements from the priority queue takes O(log(N)) time for each operation.
- For each element in the range up to `right`, we perform log(N) operations.
- Overall, the complexity is O(right * log(N)).

Space Complexity:
- The priority queue stores at most N elements at any time, giving us O(N) space complexity.

*/

#define P pair<int, int>

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Min-heap to store sums and their corresponding indices
        priority_queue<P, vector<P>, greater<P>> pq;

        // Initialize the priority queue with the first element of each possible subarray
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int cnt = 1;
        int res = 0;
        int mod = 1e9 + 7;

        // Iterate until we reach the 'right' element
        for (int i = 1; i <= right; i++) {
            int sum = pq.top().first; // Get the current smallest sum
            int idx = pq.top().second; // Get the corresponding index
            pq.pop();

            // If the current count is within the range [left, right], add to the result
            if (cnt >= left) {
                res = (res + sum) % mod;
            }

            // If the next element exists, add the new subarray sum to the priority queue
            if (idx + 1 < n) {
                pq.push({sum + nums[idx + 1], idx + 1});
            }
            cnt++;
        }

        return res;
    }
};
