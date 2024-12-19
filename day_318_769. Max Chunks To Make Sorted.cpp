/*
769. Max Chunks To Make Sorted
Solved
Medium
Topics
Companies
Hint
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

 

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
 

Constraints:

n == arr.length
1 <= n <= 10
0 <= arr[i] < n
All the elements of arr are unique.
*/

/*
Approach:
1. The problem is to divide the array into the maximum number of chunks such that when sorted individually, the entire array becomes sorted.
2. Use two helper arrays:
   - `prefix`: Stores the maximum value from the beginning up to the current index.
   - `suffix`: Stores the minimum value from the current index to the end of the array.
3. Traverse the array:
   - At each index, compare the `prefixMax` (maximum value in the left segment) and `suffixMin` (minimum value in the right segment).
   - If `prefixMax < suffixMin`, it means a new chunk can be formed at this point.
4. Add one final chunk for the last segment.

Steps:
1. Construct `prefix` and `suffix` arrays.
2. Traverse the array, comparing `prefix` and `suffix` to count the number of valid chunks.
3. Return the total chunks.

Time Complexity:
- O(n): One pass to compute `prefix` and `suffix`, and another pass to count chunks.

Space Complexity:
- O(n): Additional space for `prefix` and `suffix` arrays.

Edge Cases:
- Single element array.
- Already sorted array.
- Reverse sorted array.

*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(arr.begin(), arr.end());
        vector<int> suffix(arr.begin(), arr.end());
        
        // Fill the prefix array with maximum values up to each index
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], arr[i]);
        }
        
        // Fill the suffix array with minimum values starting from the end
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i + 1], arr[i]);
        }

        int chunk = 0;

        // Iterate through and compare prefixMax and suffixMin
        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] <= suffix[i + 1]) {
                chunk++;
            }
        }

        // Add 1 for the last chunk
        return chunk + 1;
    }
};
	
/*
Approach:
1. The problem is to divide the array into the maximum number of chunks such that when sorted individually, the entire array becomes sorted.
2. Use two helper arrays:
   - `prefix`: Stores the maximum value from the beginning up to the current index.
   - `suffix`: Stores the minimum value from the current index to the end of the array.
3. Traverse the array:
   - At each index, compare the `prefixMax` (maximum value in the left segment) and `suffixMin` (minimum value in the right segment).
   - If `prefixMax < suffixMin`, it means a new chunk can be formed at this point.
4. Add one final chunk for the last segment.

Steps:
1. Construct `prefix` and `suffix` arrays.
2. Traverse the array, comparing `prefix` and `suffix` to count the number of valid chunks.
3. Return the total chunks.

Time Complexity:
- O(n): One pass to compute `prefix` and `suffix`, and another pass to count chunks.

Space Complexity:
- O(n): Additional space for `prefix` and `suffix` arrays.

Edge Cases:
- Single element array.
- Already sorted array.
- Reverse sorted array.

*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(arr.begin(), arr.end());
        vector<int> suffix(arr.begin(), arr.end());
        
        // Fill the prefix array with maximum values up to each index
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], arr[i]);
        }
        
        // Fill the suffix array with minimum values starting from the end
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i + 1], arr[i]);
        }

        int chunk = 0;

        // Iterate through and compare prefixMax and suffixMin
        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] <= suffix[i + 1]) {
                chunk++;
            }
        }

        // Add 1 for the last chunk
        return chunk + 1;
    }
};