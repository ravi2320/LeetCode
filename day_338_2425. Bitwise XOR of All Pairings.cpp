/*
2425. Bitwise XOR of All Pairings
Solved
Medium
Topics
Companies
Hint
You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3.

 

Example 1:

Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation:
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.
 

Constraints:

1 <= nums1.length, nums2.length <= 105
0 <= nums1[i], nums2[j] <= 109

*/

/*
Approach:
1. Use properties of XOR:
   - \( a \oplus a = 0 \): XOR of a number with itself is 0.
   - \( a \oplus 0 = a \): XOR of a number with 0 is the number itself.
   - XOR is both commutative and associative.

2. Observations:
   - Each element in `nums1` is XORed with all elements in `nums2` and vice versa.
   - To optimize:
     - If `nums1.size()` is even, XOR of all `nums1` elements cancels out (because each element appears an even number of times).
     - Similarly, if `nums2.size()` is even, XOR of all `nums2` elements cancels out.

3. Cases:
   - If both sizes are even: Result is 0 (no XOR contributions).
   - If `nums1.size()` is odd: XOR all elements of `nums2`.
   - If `nums2.size()` is odd: XOR all elements of `nums1`.
   - If both sizes are odd: XOR all elements from both arrays.

Time Complexity:
- \(O(n + m)\): Where \(n\) and \(m\) are the sizes of `nums1` and `nums2`.

Space Complexity:
- \(O(1)\): Constant space is used.

*/

class Solution {
public:
    void XorNums(vector<int> &nums, int &Xor) {
        for (int num : nums) {
            Xor ^= num; // XOR all elements in the array
        }
    }

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int Xor = 0;

        // If `nums1` size is odd, XOR all elements of `nums2`
        if (n % 2 == 1) {
            XorNums(nums2, Xor);
        }
        // If `nums2` size is odd, XOR all elements of `nums1`
        if (m % 2 == 1) {
            XorNums(nums1, Xor);
        }

        return Xor; // Final XOR result
    }
};
