/*
2410. Maximum Matching of Players With Trainers

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.

The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.

Return the maximum number of matchings between players and trainers that satisfy these conditions.

 

Example 1:

Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.
Example 2:

Input: players = [1,1,1], trainers = [10]
Output: 1
Explanation:
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.
 

Constraints:

1 <= players.length, trainers.length <= 105
1 <= players[i], trainers[j] <= 109
*/

/*
Approach:
- Sort both the `players` and `trainers` arrays.
- Use two pointers (i for players, j for trainers) to try and match the weakest player with the least strong trainer who can train them.
- If the current trainer can train the player (i.e., trainer[j] >= player[i]):
    - Match them and move both pointers.
- Else, move the trainer pointer to find a stronger trainer.

Intuition:
- Greedily match each player to the smallest available trainer that can train them.
- Sorting ensures that we always try to use the minimal strength needed.

Time Complexity:
- O(n log n + m log m), where n = number of players and m = number of trainers (for sorting)
- O(n + m) for the matching process

Space Complexity:
- O(1), constant extra space used
*/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());   // Sort players by their strength
        sort(trainers.begin(), trainers.end()); // Sort trainers by their strength

        int i = 0, j = 0; // Pointers for players and trainers
        int ans = 0;

        // Try to match each player with the smallest sufficient trainer
        while(i < players.size() && j < trainers.size()) {
            // Skip trainers that are too weak
            while(j < trainers.size() && players[i] > trainers[j]) {
                j++;
            }

            // If a valid trainer is found
            if(j < trainers.size()) {
                ans++; // One match found
                i++;   // Move to next player
                j++;   // Move to next trainer
            }
        }

        return ans; // Return total matches
    }
};
