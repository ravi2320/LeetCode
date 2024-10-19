/*
1545. Find Kth Bit in Nth Binary String
Solved
Medium
Topics
Companies
Hint
Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

 

Example 1:

Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".
Example 2:

Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".
 

Constraints:

1 <= n <= 20
1 <= k <= 2n - 1
*/

/*
Approach:
- The problem is to find the k-th bit in the n-th binary string generated according to the following rules:
  - S1 = "0"
  - For n > 1, Sn = Sn-1 + "1" + invert(reverse(Sn-1))
- The approach is to recursively break down the problem using the properties of the generated string.
  - The length of Sn is `2^n - 1`.
  - The middle bit of Sn is always '1', and it divides Sn into three parts:
    1. The first part is the same as Sn-1.
    2. The second part is the middle bit ('1').
    3. The third part is the reverse and inverted version of Sn-1.
  - We recursively search for the k-th bit by determining whether it lies in the first part, the middle bit, or the third part.

Time Complexity:
- O(n), where `n` is the input number. We make recursive calls to reduce `n` by 1 each time.

Space Complexity:
- O(n), due to the recursion stack.

*/

class Solution {
public:
    // Function to find the k-th bit in the n-th binary string
    char findKthBit(int n, int k) {
        
        // Base case: S1 is just "0"
        if(n == 1){
            return '0';
        }

        // Calculate the length of the n-th binary string: 2^n - 1
        int len = (1 << n) - 1;  // Equivalent to pow(2, n) - 1

        // Case 1: If k is in the first half of the string (first part, Sn-1)
        if(k < ceil(len / 2.0)){
            return findKthBit(n-1, k);
        }
        // Case 2: If k is exactly the middle bit
        else if(k == ceil(len / 2.0)){
            return '1';  // The middle bit is always '1'
        }
        // Case 3: If k is in the second half (third part, inverted reverse of Sn-1)
        else{
            char ch = findKthBit(n-1, len - (k - 1));  // Find the corresponding bit in Sn-1
            return ch == '0' ? '1' : '0';  // Invert the bit
        }
    }
};
