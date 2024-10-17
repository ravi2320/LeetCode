/*
670. Maximum Swap
Solved
Medium
Topics
Companies
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
 

Constraints:

0 <= num <= 108
*/

/*
Approach:
- The goal is to maximize the given number by swapping at most one pair of its digits.
- We first convert the number into a string to easily manipulate its digits.
- A greedy approach is used by identifying the largest digit to the right of each position and determining if swapping can increase the number.
- Two main steps:
  1. Precompute the index of the largest digit from the right for each digit.
  2. Iterate through the number's digits, and for each digit, check if a larger digit exists on the right. If a larger digit is found, swap and return the result.
- If no beneficial swap is found, the original number is returned.

Time Complexity:
- O(n), where `n` is the number of digits in the number. We perform two linear scans: one to precompute the right max indices, and one to find the best swap.

Space Complexity:
- O(n) for storing the right maximum indices in a vector.

*/

class Solution {
public:
    int maximumSwap(int num) {
        // Convert the number to a string to manipulate individual digits
        string str = to_string(num);
        int len = str.length();
        
        // Array to store the index of the largest digit from the right side for each position
        vector<int> rightMax(len);
        rightMax[len - 1] = len - 1;  // The last digit is the largest from itself to the right
        
        // Populate the rightMax array
        for (int i = len - 2; i >= 0; i--) {
            int rightMaxIdx = rightMax[i + 1];  // Index of the largest element to the right
            int rightMaxEle = str[rightMaxIdx];  // Largest element to the right
            rightMax[i] = (str[i] > rightMaxEle) ? i : rightMaxIdx;  // Update the rightMax index
        }

        // Try to find the first digit that can be swapped to form a larger number
        for (int i = 0; i < len; i++) {
            int rightMaxIdx = rightMax[i];  // Index of the largest element to the right
            int rightMaxEle = str[rightMaxIdx];  // Largest element to the right
            // If a larger digit exists to the right, swap and return the new number
            if (str[i] < rightMaxEle) {
                swap(str[i], str[rightMaxIdx]);
                return stoi(str);  // Convert the string back to an integer and return
            }
        }

        // If no swap was made, return the original number
        return num;
    }
};
