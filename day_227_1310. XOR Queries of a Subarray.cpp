/*
1310. XOR Queries of a Subarray
Solved
Medium
Topics
Companies
Hint
You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.

 

Example 1:

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
 

Constraints:

1 <= arr.length, queries.length <= 3 * 104
1 <= arr[i] <= 109
queries[i].length == 2
0 <= lefti <= righti < arr.length
*/

/*
Approach:
1. The problem asks to perform multiple XOR operations on a subarray for each query.
   - Each query provides two indices `[L, R]`, and we need to compute the XOR of the subarray from `arr[L]` to `arr[R]`.
2. The naive approach would be to compute the XOR for each query by iterating through the elements between `L` and `R`, which takes O(n) time for each query.
3. However, this approach can be optimized using prefix XOR.
   - Define `prefixXor[i]` as the XOR of all elements from `arr[0]` to `arr[i]`. 
   - The XOR of elements from `arr[L]` to `arr[R]` can be computed as `prefixXor[R] ^ prefixXor[L-1]`, which allows us to answer each query in constant time.

Time Complexity:
- O(n + q): 
  - O(n) to compute the prefix XOR array.
  - O(q) for processing each query in constant time.

Space Complexity:
- O(n): To store the prefix XOR array.

*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n);  // Prefix XOR array
        prefixXor[0] = arr[0];

        // Compute the prefix XOR for the array
        for (int i = 1; i < n; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }

        vector<int> ans;
        // Process each query
        for (auto &query : queries) {
            int L = query[0], R = query[1];
            if (L == 0) {
                ans.push_back(prefixXor[R]);  // XOR from index 0 to R
            } else {
                ans.push_back(prefixXor[R] ^ prefixXor[L - 1]);  // XOR from index L to R
            }
        }

        return ans;
    }
};


/*
Approach:
1. The task is to answer XOR queries efficiently on subarrays. We can achieve this by transforming the input array into a prefix XOR array.
2. The prefix XOR array is built by modifying the input array itself. 
   - For each index `i`, `arr[i]` will store the XOR of all elements from `arr[0]` to `arr[i]`.
3. For each query `[L, R]`, the XOR of the subarray from `arr[L]` to `arr[R]` can be computed using:
   - If L > 0, the XOR is `arr[R] ^ arr[L-1]`.
   - If L == 0, the XOR is just `arr[R]` (since we are taking the XOR from the start).
4. This reduces the time complexity of processing each query to O(1) after preprocessing.

Time Complexity:
- O(n + q): 
  - O(n) to build the prefix XOR array.
  - O(q) for processing each query in constant time.

Space Complexity:
- O(1) extra space, excluding the result array.

*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        // Step 1: Compute prefix XOR
        for (int i = 1; i < n; i++) {
            arr[i] ^= arr[i - 1];  // Each element arr[i] becomes the XOR of arr[0] to arr[i]
        }

        vector<int> ans;
        // Step 2: Answer each query
        for (auto &query : queries) {
            int L = query[0], R = query[1];
            
            // XOR from arr[L] to arr[R]
            if (L > 0) {
                ans.push_back(arr[R] ^ arr[L - 1]);  // XOR from L to R
            } else {
                ans.push_back(arr[R]);  // XOR from 0 to R
            }
        }

        return ans;
    }
};
