/*
907. Sum of Subarray Minimums
Solved
Medium
Topics
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int length = arr.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);

        stack<int> st;

        for (int i = 0; i < length; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty())
                left[i] = st.top();

            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = length - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty())
                right[i] = st.top();

            st.push(i);
        }

        long long int ans = 0;
        long long int mod = 1e9 + 7;
        for (int i = 0; i < length; i++) {
            ans += (long long int)(i - left[i]) * (right[i] - i) % mod * arr[i] % mod;
            ans = ans % mod;
        }

        return static_cast<int>(ans);
    }
};
