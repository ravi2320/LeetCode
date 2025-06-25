/*
2040. Kth Smallest Product of Two Sorted Arrays

avatar
Discuss Approach
arrow-up
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.
 

Example 1:

Input: nums1 = [2,5], nums2 = [3,4], k = 2
Output: 8
Explanation: The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2nd smallest product is 8.
Example 2:

Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
Output: 0
Explanation: The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6th smallest product is 0.
Example 3:

Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
Output: -6
Explanation: The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3rd smallest product is -6.
 

Constraints:

1 <= nums1.length, nums2.length <= 5 * 104
-105 <= nums1[i], nums2[j] <= 105
1 <= k <= nums1.length * nums2.length
nums1 and nums2 are sorted.
*/

/*
Approach:
We are given two sorted arrays (`nums1` and `nums2`) and need to find the `k-th` smallest product
formed by picking one element from each array.

Since direct generation of all products (O(n^2)) is inefficient, we use **Binary Search** on the value of the product.
We search for the smallest number `x` such that there are at least `k` products ≤ `x`.

Key Insight:
- We binary search in the range [-1e10, 1e10] for the product value.
- For each mid (product), we count how many pairs (nums1[i], nums2[j]) satisfy nums1[i]*nums2[j] ≤ mid.

The function `findCntSmallest` uses two-pointer/binary search technique:
- If nums1[i] ≥ 0, increasing nums2[j] increases product.
- If nums1[i] < 0, increasing nums2[j] decreases product.

Time Complexity:
- O(n * log m * log R): where n = size of nums1, m = size of nums2, R = search space (1e10)
  For each nums1[i], we binary search over nums2 → O(log m)
  And outer binary search over product range → O(log R)

Space Complexity:
- O(1): No extra space apart from counters.
*/

class Solution {
public:
    // Function to count the number of pairs with product <= midProd
    long long findCntSmallest(vector<int> &nums1, vector<int> &nums2, long long &midProd) {
        long long productCnt = 0;
        int n = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] >= 0) {
                // Binary search for largest j such that nums1[i] * nums2[j] <= midProd
                int l = 0, r = n - 1, m = -1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long prod = 1LL * nums1[i] * nums2[mid];
                    if (prod <= midProd) {
                        m = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                productCnt += (m + 1);
            } else {
                // nums1[i] < 0 → increasing nums2 decreases product
                // Binary search for smallest j such that nums1[i] * nums2[j] <= midProd
                int l = 0, r = n - 1, m = n;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long prod = 1LL * nums1[i] * nums2[mid];
                    if (prod <= midProd) {
                        m = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                productCnt += (n - m);
            }
        }

        return productCnt;
    }

    // Main function to find k-th smallest product
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long res;
        long long l = -1e10, r = 1e10;

        // Binary search on product value
        while (l <= r) {
            long long midProduct = l + (r - l) / 2;
            long long cntSmallest = findCntSmallest(nums1, nums2, midProduct);

            if (cntSmallest >= k) {
                res = midProduct;
                r = midProduct - 1;
            } else {
                l = midProduct + 1;
            }
        }

        return res;
    }
};
