/*
1518. Water Bottles
Solved
Easy
Topics
Companies
Hint
There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

 

Example 1:


Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.
Example 2:


Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
Number of water bottles you can drink: 15 + 3 + 1 = 19.
 

Constraints:

1 <= numBottles <= 100
2 <= numExchange <= 100
*/

/*
 * Intuition:
 * The problem is to determine how many water bottles one can drink if you can exchange a certain number of empty bottles for a full bottle.
 * We keep track of the total number of bottles consumed and continue to exchange empty bottles for full ones until we can't anymore.
 *
 * Time Complexity: O(log(numBottles)), because in each iteration, the number of bottles is reduced by a fraction, specifically (numBottles / numExchange).
 * Space Complexity: O(1), as we only use a constant amount of extra space.
 */

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles; // Initialize the total count of water bottles consumed

        // Continue the process while we have enough empty bottles to exchange for a new full bottle
        while (numBottles >= numExchange) {
            ans += numBottles / numExchange; // Add the number of new bottles we can get by exchange
            numBottles = (numBottles / numExchange) + (numBottles % numExchange); // Update the number of bottles left: new full bottles + remaining empty bottles
        }

        return ans; // Return the total number of bottles consumed
    }
};
