/*
877. Stone Game
Solved
Medium
Topics
Companies
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

 

Example 1:

Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
Example 2:

Input: piles = [3,7,2,3]
Output: true
 

Constraints:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles[i]) is odd.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
218.7K
Submissions
310.9K
Acceptance Rate
70.3%
Topics
Array
Math
Dynamic Programming
Game Theory
*/

class Solution {
public:
    int solve(vector<int>& a, int i, int j, map<pair<int, int>, int> &hash)
    {
        if(i > j) return 0;

        pair<int, int> key = make_pair(i, j);
        if(hash.find(key) != hash.end())
            return hash[key];

        int ans = max(
                        a[i] + min(solve(a, i+2, j, hash), solve(a, i+1, j-1, hash)),
                       a[j] + min(solve(a, i+1, j-1, hash), solve(a, i, j-2, hash))
        );

        hash[key] = ans;

        return ans;
    } 
    bool stoneGame(vector<int>& piles) {
        map<pair<int, int>, int> hash;
        int total = 0;
        for(int i : piles)
                total += i;
        int alice_score = solve(piles, 0, piles.size()-1, hash);
        int bob_score = total - alice_score; 
        return alice_score > bob_score ? 1:0;
    }
};