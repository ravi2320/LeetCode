/*
2364. Count Number of Bad Pairs
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

 

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

/*
Approach:
1. Transform the array by modifying each element to `nums[i] - i`.
2. Use a **hashmap** (`unordered_map<int, int> mp`) to store the frequency of these transformed values.
3. The total number of pairs `(i, j)` where `i < j` is `n * (n - 1) / 2`.
4. To count **good pairs**, check how many times a transformed value has appeared before, since pairs `(i, j)` with the same transformed value are good pairs.
5. Subtract the number of good pairs from the total pairs to get the number of bad pairs.

Intuition:
- A pair `(i, j)` is **good** if `nums[i] - i == nums[j] - j`, meaning `nums[i] - nums[j] == i - j`.
- If we store `nums[i] - i` in a map, we can count how many times each value appears, allowing efficient calculation of good pairs.
- Bad pairs = **Total pairs - Good pairs**.

Time Complexity: **O(N)**
- The transformation and traversal of `nums` take **O(N)**.
- The unordered map operations (`insert`, `lookup`) are **O(1) on average**, making the entire approach linear.

Space Complexity: **O(N)**
- The unordered map stores at most **N** elements.
*/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = (1LL * n * (n - 1)) / 2; // Total pairs
        
        unordered_map<int, int> mp; // Map to store transformed values count
        long long goodPairs = 0;

        // Count good pairs using the transformation nums[i] - i
        for (int i = 0; i < n; i++) {
            int transformedValue = nums[i] - i;
            if (mp.count(transformedValue)) {
                goodPairs += mp[transformedValue]; // Existing count contributes to good pairs
            }
            mp[transformedValue]++; // Increment count for this transformed value
        }

        return totalPairs - goodPairs; // Bad pairs = Total pairs - Good pairs
    }
};