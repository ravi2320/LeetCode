/*
3370. Smallest Number With All Set Bits

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given a positive number n.

Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits

 

Example 1:

Input: n = 5

Output: 7

Explanation:

The binary representation of 7 is "111".

Example 2:

Input: n = 10

Output: 15

Explanation:

The binary representation of 15 is "1111".

Example 3:

Input: n = 3

Output: 3

Explanation:

The binary representation of 3 is "11".

 

Constraints:

1 <= n <= 1000
*/

// Intuition:
// The problem asks us to find the smallest number that is greater than or equal to a given number `n`
// from a set of numbers which are all in the form (2^i - 1) where i ranges from 1 to 10. These numbers 
// represent numbers that are all formed by setting all bits to 1 in a number, i.e., 1, 3, 7, 15, ..., 1023.
//
// The goal is to find the smallest number from this set that is greater than or equal to `n` using a binary search.
// The binary search will allow us to efficiently locate the smallest such number from the list of numbers.


/* Time Complexity:
   - The binary search takes O(log N) where N is the number of elements in `arr`.
   - In this case, `arr` always contains 10 elements, so the complexity is O(log 10), which is constant time O(1).
   - Generating the list `arr` also takes O(10) time, which is constant.

   Hence, the overall time complexity is O(1), because the list size (10) is fixed.

   Space Complexity:
   - We are storing 10 elements in the vector `arr`, so the space complexity is O(10), which is effectively O(1) because the list size is constant.

   Hence, the space complexity is O(1). */

class Solution {
public:
    // Binary Search function:
    // This function finds the index of the smallest number in `arr` that is greater than or equal to `num`
    int binarySearch(vector<int> &arr, int num) {
        int low = 0, high = arr.size() - 1; // Set the search range from 0 to the size of arr minus 1
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate the middle index
            if (arr[mid] >= num) {  // If the middle element is greater than or equal to num, search left
                high = mid - 1;
            } else {  // Otherwise, search right
                low = mid + 1;
            }
        }
        return low; // Return the index of the smallest number that is >= num
    }
    
    // Function to find the smallest number >= n from the sequence of (2^i - 1)
    int smallestNumber(int n) {
        vector<int> arr; // Create a vector to store the sequence of numbers (2^i - 1)
        
        // Generate numbers (2^i - 1) for i from 1 to 10
        for (int i = 1; i <= 10; i++) {
            int num = (1 << i) - 1; // (1 << i) is equivalent to 2^i
            arr.push_back(num); // Add the number to the array
        }

        // Use binary search to find the smallest number >= n
        int idx = binarySearch(arr, n);
        
        // Return the number at the found index
        return arr[idx];
    }
};


#include <cmath>  // for log2

/*
 * Intuition:
 * The goal is to find the smallest number that has the same number of bits as `n` but is greater than or equal to `n`.
 * 1. First, we calculate the number of bits required to represent the number `n` in binary using `log2(n) + 1`.
 * 2. Then, we create the largest number that can be represented with `bits` number of 1s. This is done using the formula `(1 << bits) - 1`.
 * 3. If this largest number (`num`) is smaller than `n`, we know that `n` requires one more bit to fully represent it. So, we return `(1 << (bits + 1)) - 1`.
 * 4. Otherwise, we return `num` because it is the smallest number that has the same number of bits as `n`.
 * 
 * Time Complexity:
 * - The time complexity is **O(1)** because the operations in the function (logarithmic calculation, bit shifting) are constant time operations.
 * 
 * Space Complexity:
 * - The space complexity is **O(1)** since we are only using a few integer variables and no additional data structures.
 */

class Solution {
public:
    int smallestNumber(int n) {
        // Step 1: Calculate the number of bits required to represent `n` in binary
        int bits = log2(n) + 1;

        // Step 2: Create a number with all `bits` set to 1 (e.g., for 5 bits: 11111)
        int num = (1 << bits) - 1;

        // Step 3: If the created number is smaller than `n`, return the smallest number with one more bit
        return num < n ? (1 << (bits + 1)) - 1 : num;
    }
};
