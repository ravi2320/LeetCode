/*
846. Hand of Straights
Solved
Medium
Topics
Companies
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length
*/

// Intuition:
// - To determine if the given hand of cards can be rearranged into groups of size `groupSize` where each group consists of consecutive cards.
// - Utilize a map to keep track of the frequency of each card, and attempt to form the required groups by starting from the smallest card each time.

// Approach:
// 1. Check if the total number of cards is divisible by `groupSize`. If not, it's impossible to form the required groups, so return false.
// 2. Use a map to count the frequency of each card in the hand.
// 3. Iterate through the map, starting with the smallest card each time and attempting to form a group of consecutive cards of size `groupSize`.
// 4. If a group cannot be formed because a required card is missing, return false.
// 5. Decrease the count of each card in the group, and remove it from the map if the count drops to zero.
// 6. If all groups are successfully formed, return true.

// Time Complexity: O(n log n), where n is the size of the hand. This is because we use a map (which has log n insertion and deletion time) and iterate through the hand once.
// Space Complexity: O(n), where n is the size of the hand, for storing the frequency of each card in the map.

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        // If the total number of cards is not divisible by groupSize, return false
        if (n % groupSize != 0)
            return false;

        // Map to count the frequency of each card
        map<int, int> mp;
        for (int handNum : hand) {
            mp[handNum]++;
        }

        // Iterate through the map to form groups
        while (!mp.empty()) {
            int curr = mp.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                // If the required card for the group is missing, return false
                if (mp[curr + i] == 0)
                    return false;

                // Decrease the count of the current card
                mp[curr + i]--;

                // Remove the card from the map if its count drops to zero
                if (mp[curr + i] < 1)
                    mp.erase(curr + i);
            }
        }

        return true;
    }
};
