/*
781. Rabbits in Forest
Solved
Medium
Topics
Companies
There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.

 

Example 1:

Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
Example 2:

Input: answers = [10,10,10]
Output: 11
 

Constraints:

1 <= answers.length <= 1000
0 <= answers[i] < 1000
*/

/*
Intuition:
Each rabbit's answer `x` means there are exactly `x` other rabbits (with the same color) — 
which implies a group of `(x + 1)` rabbits with the same color including itself.

If multiple rabbits say `x`, we can group them into groups of size `(x + 1)`. 
If we have more than `(x + 1)` such rabbits, we need to start another group, and so on.

Approach:
1. Count the frequency of each answer.
2. For each unique answer `x`:
   - Calculate how many full groups of `(x + 1)` are needed using `ceil(cnt / (x + 1))`.
   - Multiply the number of groups by `(x + 1)` to get total rabbits for this answer.
3. Sum all such group sizes to get the final result.

Time Complexity: O(N)
- N is the number of elements in `answers`.

Space Complexity: O(M)
- M is the number of unique answers in the map.
*/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;

        // Count frequency of each answer
        for(int &x : answers){
            mp[x]++;
        }

        int total = 0;

        // Calculate total number of rabbits
        for(auto &itr : mp){
            int x = itr.first;       // The answer given by rabbits
            int cnt = itr.second;    // Number of rabbits giving this answer

            int groupSize = x + 1;   // Each group must have (x + 1) rabbits
            int groups = ceil((double)cnt / groupSize);  // Number of such groups needed

            total += groups * groupSize;  // Total rabbits in these groups
        }

        return total;
    }
};