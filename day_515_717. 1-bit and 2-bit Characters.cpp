/*
717. 1-bit and 2-bit Characters
Solved

avatar
Discuss Approach
arrow-up
Easy
Topics
premium lock icon
Companies
Hint
We have two special characters:

The first character can be represented by one bit 0.
The second character can be represented by two bits (10 or 11).
Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

 

Example 1:

Input: bits = [1,0,0]
Output: true
Explanation: The only way to decode it is two-bit character and one-bit character.
So the last character is one-bit character.
Example 2:

Input: bits = [1,1,1,0]
Output: false
Explanation: The only way to decode it is two-bit character and two-bit character.
So the last character is not one-bit character.
 

Constraints:

1 <= bits.length <= 1000
bits[i] is either 0 or 1.
*/

class Solution {
  public:
    /**
     * Intuition:
     * The problem is about determining whether the last character in a binary encoding can be represented 
     * by a 1-bit character or not. 
     * The encoding follows these rules:
     * 1. A 1-bit character is represented by 0.
     * 2. A 2-bit character is represented by 10 or 11.
     * The goal is to check if the last character in the given binary array can be decoded as a 1-bit character.

     * Approach:
     * 1. Traverse the `bits` array from the start to the end.
     * 2. If a bit is `0`, this is a valid 1-bit character, so check if it is the last bit.
     * 3. If a bit is `1`, it indicates a start of a 2-bit character, so skip the next bit by incrementing the index.
     * 4. The loop stops as soon as we find a 1-bit character at the end.
     * 5. If we reach the last bit, return `true` if it's a 1-bit character.
     * 6. If we find a 2-bit character, continue checking the next bits.
     
     * Time Complexity:
     * - We are iterating over the `bits` array once, so the time complexity is O(n), where n is the size of the array.
     
     * Space Complexity:
     * - We are using a constant amount of extra space (only a few variables), so the space complexity is O(1).
     */
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        
        // Traverse the bits array
        for (int i = 0; i < n; i++) {
            if (bits[i] == 0) {
                // If the current bit is 0, check if it's the last bit
                if (i == n - 1)
                    return true;  // It's a 1-bit character and it's the last bit
            } 
            else {
                // If the current bit is 1, it indicates a 2-bit character, so skip the next bit
                i++;
            }
        }

        // If we reach here, it means the last bit is part of a 2-bit character
        return false;
    }
};
