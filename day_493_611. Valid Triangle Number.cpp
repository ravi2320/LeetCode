/*
611. Valid Triangle Number

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

 

Example 1:

Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Example 2:

Input: nums = [4,2,3,4]
Output: 4
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
*/

/*
Approach:
1. A valid triangle can be formed if for three sides (a, b, c) where a ≤ b ≤ c:
       a + b > c
2. Sort the array so that we can easily fix two smaller sides and binary search for the third side.
3. For each pair (i, j):
   - Use binary search to find the maximum index `idx` such that nums[idx] < nums[i] + nums[j].
   - All numbers between (j+1 .. idx) are valid third sides.
   - Add (idx - j) to the answer.
4. Repeat this for all pairs.

Intuition:
- Sorting helps reduce the triangle inequality check to just `a + b > c` since c is the largest.
- Instead of a triple nested loop (O(n³)), we cut down the third loop using binary search (O(log n)).

Time Complexity:
- O(n² log n): Sorting O(n log n) + for each pair we do binary search.
Space Complexity:
- O(1) extra space (ignoring sort in-place).

*/

class Solution {
public:
    // Custom binary search: finds largest index <= high where nums[idx] < target
    int binarySearch(int low, int high, vector<int> &nums, int target) {
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < target) {
                idx = mid;          // store potential valid index
                low = mid + 1;      // try to find bigger index
            }
            else {
                high = mid - 1;     // shrink range
            }
        }

        return idx; // -1 if not found
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        if (n < 3) return 0;

        sort(nums.begin(), nums.end()); // sort for triangle inequality simplification

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;  // skip 0-length side (invalid)

            for (int j = i + 1; j < n; j++) {
                int idx = binarySearch(j + 1, n - 1, nums, nums[i] + nums[j]);

                if (idx != -1) {
                    ans += idx - j;  // count valid third sides
                }
            }
        }

        return ans;
    }
};


/*
Approach:
1. Sort the array so that we can leverage the triangle inequality easily.
   For any three numbers a ≤ b ≤ c, they form a triangle if a + b > c.
2. Fix the largest side (nums[k]) and try to find two smaller sides (nums[i], nums[j]) using two pointers:
   - Start with i = 0 and j = k-1.
   - If nums[i] + nums[j] > nums[k], then all elements between i and j also work
     (because nums[i+1], nums[i+2] ... nums[j-1] will be ≥ nums[i]).
     → Add (j - i) to answer, then move j--.
   - Otherwise, increment i++ to try a larger sum.
3. Repeat for all possible k (from n-1 down to 2).

Intuition:
- Sorting ensures that when nums[i] + nums[j] > nums[k], every number between i and j with nums[j] also forms a valid triangle.
- Instead of O(n² log n) with binary search, we use two pointers in O(n²).

Time Complexity:
- O(n²): Sorting takes O(n log n), and the main loop is O(n²).
Space Complexity:
- O(1) extra space (ignoring sorting).

*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        if (n < 3) return 0;

        // Sort to apply two-pointer technique
        sort(nums.begin(), nums.end());

        // Fix the largest side nums[k]
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += j - i; // all pairs between i..j-1 are valid
                    j--;          // decrease j for next possibility
                }
                else {
                    i++;          // increase i to get larger sum
                }
            }
        }

        return ans;
    }
};