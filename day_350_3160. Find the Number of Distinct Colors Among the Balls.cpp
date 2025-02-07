/*
3160. Find the Number of Distinct Colors Among the Balls
Solved
Medium
Topics
Companies
Hint
You are given an integer limit and a 2D array queries of size n x 2.

There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.

Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

Note that when answering a query, lack of a color will not be considered as a color.

 

Example 1:

Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]

Output: [1,2,2,3]

Explanation:



After query 0, ball 1 has color 4.
After query 1, ball 1 has color 4, and ball 2 has color 5.
After query 2, ball 1 has color 3, and ball 2 has color 5.
After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.
Example 2:

Input: limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]

Output: [1,2,2,3,4]

Explanation:



After query 0, ball 0 has color 1.
After query 1, ball 0 has color 1, and ball 1 has color 2.
After query 2, ball 0 has color 1, and balls 1 and 2 have color 2.
After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3 has color 4.
After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has color 4, and ball 4 has color 5.
 

Constraints:

1 <= limit <= 109
1 <= n == queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] <= limit
1 <= queries[i][1] <= 109
*/

/*
Approach:
1. Maintain two hash maps:
   - `ballColor`: Maps each ball to its assigned color.
   - `colorCnt`: Stores the count of each color present.
2. Iterate through each query:
   - If the ball has been assigned a previous color, decrement its count in `colorCnt`.
   - If the count of the previous color reaches zero, remove it from `colorCnt`.
   - Assign the new color to the ball and increment its count in `colorCnt`.
   - Append the current distinct color count to the result.
   
Intuition:
- Since each ball can change colors multiple times, keeping track of the latest color for each ball allows efficient updates.
- Using `colorCnt`, we can maintain the count of distinct colors dynamically.
- By erasing colors that reach zero count, we ensure an accurate distinct color count at each step.

Time Complexity: **O(Q)**  
- Each query requires constant-time updates in two hash maps, leading to **O(1)** per query.
- Given `Q` queries, the overall complexity is **O(Q)**.

Space Complexity: **O(L)**  
- `ballColor` stores at most `L` entries (one per unique ball).
- `colorCnt` stores at most `L` entries (one per unique color).
- Thus, the worst-case space complexity is **O(L)**.
*/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor; // Maps each ball to its assigned color
        unordered_map<int, int> colorCnt;  // Tracks the count of each color
        vector<int> res;

        // Process each query
        for (vector<int>& query : queries) {
            int ball = query[0];  // Ball number
            int color = query[1]; // New color for the ball

            // If the ball already has a color, decrement the count of the previous color
            if (ballColor.find(ball) != ballColor.end()) {
                int prevColor = ballColor[ball];

                colorCnt[prevColor]--; // Reduce the count of previous color

                // Remove the color entry if its count becomes zero
                if (colorCnt[prevColor] == 0) {
                    colorCnt.erase(prevColor);
                }
            }
            
            // Assign the new color to the ball
            ballColor[ball] = color;

            // Increase count for the new color
            colorCnt[color]++;

            // Store the number of distinct colors in the result
            res.push_back(colorCnt.size());
        }

        return res;
    }
};