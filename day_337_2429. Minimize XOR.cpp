/*
2429. Minimize XOR
Solved
Medium
Topics
Companies
Hint
Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

 

Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
 

Constraints:

1 <= num1, num2 <= 109
*/

/*
Approach:
1. Calculate the number of set bits (`1s`) in `num2` using `__builtin_popcount`.
2. Compare the number of set bits in `num1` with `num2`:
   - If `num1` has fewer set bits than required, set additional bits starting from the least significant bit.
   - If `num1` has more set bits than required, unset bits starting from the least significant bit.
3. Use bitwise operations to modify `num1` directly, ensuring the number of set bits in the result matches `num2`.

Intuition:
- The goal is to minimize the XOR value between `num1` and the result `x`.
- Setting or unsetting bits starting from the least significant bit helps maintain the smallest possible number.

Time Complexity:
- \(O(32)\) (constant): The loop iterates over a fixed number of bits (32 for a standard integer).
- \(O(1)\) for operations like `setBit`, `unsetBit`, and `isSetBit`.

Space Complexity:
- \(O(1)\): No additional space is used apart from a few variables.

Edge Cases:
1. `num1` already has the same number of set bits as `num2`.
2. All bits in `num1` are already set or unset.
3. Large values of `num1` and `num2`.

*/

class Solution {
public:
    // Helper function to check if a specific bit is set
    bool isSetBit(int &x, int bit) {
        return x & (1 << bit);
    }

    // Helper function to set a specific bit
    void setBit(int &x, int bit) {
        x |= (1 << bit);
    }

    // Helper function to unset a specific bit
    void unsetBit(int &x, int bit) {
        x &= ~(1 << bit);
    }

    int minimizeXor(int num1, int num2) {
        int x = num1; // Start with num1
        int requiredSetBits = __builtin_popcount(num2); // Count set bits in num2
        int currSetBits = __builtin_popcount(num1); // Count set bits in num1
        int bit = 0; // Bit position to process

        // If current set bits are fewer than required, set additional bits
        if (currSetBits < requiredSetBits) {
            while (currSetBits < requiredSetBits) {
                if (!isSetBit(x, bit)) { // Check if the bit is not set
                    setBit(x, bit); // Set the bit
                    currSetBits++; // Increment the count of set bits
                }
                bit++; // Move to the next bit
            }
        }
        // If current set bits are more than required, unset extra bits
        else if (currSetBits > requiredSetBits) {
            while (currSetBits > requiredSetBits) {
                if (isSetBit(x, bit)) { // Check if the bit is set
                    unsetBit(x, bit); // Unset the bit
                    currSetBits--; // Decrement the count of set bits
                }
                bit++; // Move to the next bit
            }
        }

        return x; // Return the modified number
    }
};

/*
Approach:
1. To minimize the XOR of `num1` and the result `x`, we want `x` to retain as many high-order bits as possible from `num1`.
2. Start by copying the highest set bits of `num1` into `x` until the number of set bits in `x` equals the required set bits (`__builtin_popcount(num2)`).
3. If additional set bits are needed, iterate through the lower-order unset bits of `x` and set them until the count matches.

Intuition:
- XOR is minimized when the binary representation of `x` aligns closely with `num1`.
- Using high-order bits from `num1` first ensures the smallest possible XOR value.

Time Complexity:
- \(O(32)\) (constant): The loops iterate over a fixed number of bits (32 for a standard integer).

Space Complexity:
- \(O(1)\): Only a few variables are used.

Edge Cases:
1. `num1` already has fewer or exactly the required set bits.
2. Large values of `num1` and `num2`.
3. `num2` with all bits set or no bits set.

*/

class Solution {
public:
    // Helper function to check if a specific bit is set
    bool isSetBit(int &x, int bit) {
        return x & (1 << bit);
    }

    // Helper function to check if a specific bit is unset
    bool isUnsetBit(int &x, int bit) {
        return !(x & (1 << bit));
    }

    // Helper function to set a specific bit
    void setBit(int &x, int bit) {
        x |= (1 << bit);
    }

    int minimizeXor(int num1, int num2) {
        int x = 0; // Initialize the result as 0
        int requiredSetBits = __builtin_popcount(num2); // Count set bits in num2

        // Step 1: Copy high-order set bits from num1 to x
        for (int bit = 31; bit >= 0 && requiredSetBits > 0; bit--) {
            if (isSetBit(num1, bit)) {
                setBit(x, bit); // Set the corresponding bit in x
                requiredSetBits--; // Decrease the count of required set bits
            }
        }

        // Step 2: Set lower-order unset bits in x if more bits are required
        for (int bit = 0; bit <= 31 && requiredSetBits > 0; bit++) {
            if (isUnsetBit(x, bit)) {
                setBit(x, bit); // Set the bit
                requiredSetBits--; // Decrease the count of required set bits
            }
        }

        return x; // Return the result
    }
};
