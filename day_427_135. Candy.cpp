/*
135. Candy
Solved
Hard
Topics
premium lock icon
Companies
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/

/*
Approach:
- Traverse the ratings array twice:
  1. From left to right to ensure each child has more candies than the left neighbor if rated higher.
  2. From right to left to ensure the same condition with respect to the right neighbor.
- Take the maximum of both passes at each index to satisfy both conditions.

Intuition:
- Every child must have at least one candy.
- If a child has a higher rating than a neighbor, they should get more candies.
- Doing two passes helps enforce this from both directions without missing constraints.

Time Complexity: O(n)
- Each pass (left-to-right and right-to-left) takes linear time.

Space Complexity: O(n)
- Two auxiliary arrays of size `n` are used for the left-to-right and right-to-left passes.
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // Initialize left-to-right and right-to-left candy counts with 1
        vector<int> L2R(n, 1), R2L(n, 1);

        // Left to right pass
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                L2R[i] = L2R[i - 1] + 1; // Give more candy than the left neighbor
            }

            // Right to left pass at the same time (from back)
            if(ratings[n - i - 1] > ratings[n - i]) {
                R2L[n - i - 1] = R2L[n - i] + 1; // Give more candy than the right neighbor
            }
        }

        // Final total candies is the max at each position
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += max(L2R[i], R2L[i]);
        }

        return ans;
    }
};
														 
/*
Approach:
- Traverse the ratings array using a greedy method to identify **increasing** (peak) and **decreasing** (dip) sequences.
- Every increase in ratings results in additional candies for that child based on position in the increasing sequence.
- Similarly, every decrease in ratings does the same for the descending sequence.
- We subtract the overlap of the peak and dip minimum once since the "turning point" child gets counted twice.

Intuition:
- Start by assigning 1 candy to each child (default).
- For increasing ratings, each next child must get more candy (simulate like 1, 2, 3, ...).
- For decreasing ratings, it’s the same (but from the back): simulate like ..., 3, 2, 1.
- At the valley/peak where both increasing and decreasing sequences meet, the middle child would be counted twice — we subtract the smaller of the two.

Time Complexity: O(n)
- We scan the entire array once with pointer `i` moving forward in each loop.

Space Complexity: O(1)
- No extra space is used apart from constant variables.
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // Minimum 1 candy per child
        int candy = n;

        // Start from the second child
        int i = 1;

        while(i < n) {
            // If current rating equals previous, move on
            if(ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            // Count strictly increasing sequence (peak)
            int peak = 0;
            while(i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candy += peak;
                i++;
            }

            // Count strictly decreasing sequence (dip)
            int dip = 0;
            while(i < n && ratings[i] < ratings[i - 1]) {
                dip++;
                candy += dip;
                i++;
            }

            // Subtract the smaller one (peak or dip) to avoid double count
            candy -= min(peak, dip);
        }

        return candy;
    }
};