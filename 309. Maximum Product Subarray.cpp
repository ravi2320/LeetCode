/*
Maximum Product Subarray
Difficulty: MediumAccuracy: 18.09%Submissions: 396K+Points: 4
Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr.

Note: It is guaranteed that the output fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.
Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.
Input: arr[] = [2, 3, 4] 
Output: 24 
Explanation: For an array with all positive elements, the result is product of all elements. 
Constraints:
1 ≤ arr.size() ≤ 106
-10  ≤  arr[i]  ≤  10
*/

/*
Approach:
1. The problem involves finding the maximum product of a contiguous subarray.
2. A key challenge with subarray product problems is handling negative numbers and zeros.
3. We perform two passes to handle potential negative values that could become positive when considering the subarray in reverse.
   - First pass: Iterate from left to right, tracking the current product.
   - Second pass: Iterate from right to left, allowing previously "negative" subarrays to become positive.
4. If the current product hits zero, reset it to 1 for fresh calculation.

Steps:
1. Traverse the array twice:
   - In the first pass, calculate the product from the start to the end.
   - In the second pass, calculate the product from the end to the start.
2. Keep track of the maximum product encountered during these traversals.
3. If at any point the product becomes zero (indicating a subarray cannot continue), reset it to 1.
4. Return the maximum product.

Time Complexity:
- O(n) — we are traversing the array twice.

Space Complexity:
- O(1) — only a few integer variables are used for tracking the product.

*/

class Solution {
  public:
    // Function to find the maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int prod = 1;          // To keep track of current product
        int res = INT_MIN;     // To store the maximum product found

        // First pass: from left to right
        for(int i = 0; i < n; i++) {
            prod *= arr[i];    // Update the product
            res = max(res, prod); // Update result with the maximum product so far
            
            // Reset product if it becomes zero
            if(prod == 0) {
                prod = 1;
            }
        }

        // Second pass: from right to left
        prod = 1; // Reset product for reverse pass
        for(int i = n - 1; i >= 0; i--) {
            prod *= arr[i];    // Update the product
            res = max(res, prod); // Update result with the maximum product so far
            
            // Reset product if it becomes zero
            if(prod == 0) {
                prod = 1;
            }
        }

        return res; // Return the maximum product found
    }
};
