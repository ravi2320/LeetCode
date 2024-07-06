/*
2582. Pass the Pillow
Solved
Easy
Topics
Companies
Hint
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

 

Example 1:

Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
After five seconds, the 2nd person is holding the pillow.
Example 2:

Input: n = 3, time = 2
Output: 3
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
After two seconds, the 3rd person is holding the pillow.
 

Constraints:

2 <= n <= 1000
1 <= time <= 1000
*/

/*
 * Intuition:
 * The pillow passing problem can be visualized as passing an item in a circle. The challenge is to determine the position of the pillow after a certain amount of time, considering that the direction of passing changes every (n-1) passes.
 * By calculating the number of full cycles (div) and the remaining passes (rem), we can determine the position based on whether the current cycle is even or odd.
 *
 * Time Complexity: O(1), as it involves basic arithmetic operations.
 * Space Complexity: O(1), as no additional space is used apart from a few variables.
 */

class Solution {
public:
    int passThePillow(int n, int time) {
        // Calculate the number of full cycles and remaining passes
        int div = time / (n - 1);
        int rem = time % (n - 1);
        
        // If the number of full cycles is even, the direction hasn't changed, so we simply add the remainder
        if(div % 2 == 0)
            return 1 + rem;
        
        // If the number of full cycles is odd, the direction has changed, so we subtract the remainder from n
        return n - rem;
    }
};
