/*
3027. Find the Number of Ways to Place People II

Hard

You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

We define the right direction as positive x-axis (increasing x-coordinate) and the left direction as negative x-axis (decreasing x-coordinate). Similarly, we define the up direction as positive y-axis (increasing y-coordinate) and the down direction as negative y-axis (decreasing y-coordinate)

You have to place n people, including Alice and Bob, at these points such that there is exactly one person at every point. Alice wants to be alone with Bob, so Alice will build a rectangular fence with Alice's position as the upper left corner and Bob's position as the lower right corner of the fence (Note that the fence might not enclose any area, i.e. it can be a line). If any person other than Alice and Bob is either inside the fence or on the fence, Alice will be sad.

Return the number of pairs of points where you can place Alice and Bob, such that Alice does not become sad on building the fence.

Note that Alice can only build a fence with Alice's position as the upper left corner, and Bob's position as the lower right corner. For example, Alice cannot build either of the fences in the picture below with four corners (1, 1), (1, 3), (3, 1), and (3, 3), because:

With Alice at (3, 3) and Bob at (1, 1), Alice's position is not the upper left corner and Bob's position is not the lower right corner of the fence.
With Alice at (1, 3) and Bob at (1, 1), Bob's position is not the lower right corner of the fence.

 

Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 0
Explanation: There is no way to place Alice and Bob such that Alice can build a fence with Alice's position as the upper left corner and Bob's position as the lower right corner. Hence we return 0. 
Example 2:


Input: points = [[6,2],[4,4],[2,6]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
- Place Alice at (4, 4) and Bob at (6, 2).
- Place Alice at (2, 6) and Bob at (4, 4).
You cannot place Alice at (2, 6) and Bob at (6, 2) because the person at (4, 4) will be inside the fence.
Example 3:


Input: points = [[3,1],[1,3],[1,1]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
- Place Alice at (1, 1) and Bob at (3, 1).
- Place Alice at (1, 3) and Bob at (1, 1).
You cannot place Alice at (1, 3) and Bob at (3, 1) because the person at (1, 1) will be on the fence.
Note that it does not matter if the fence encloses any area, the first and second fences in the image are valid.
 

Constraints:

2 <= n <= 1000
points[i].length == 2
-109 <= points[i][0], points[i][1] <= 109
All points[i] are distinct.
*/

/*
Approach:
1. Sort the points:
   - First by x-coordinate in ascending order.
   - If x is the same, then by y-coordinate in descending order.
   This ensures that when we iterate, we only need to check points to the right
   and higher y values are handled properly.
2. For each point `i`, iterate over points `j > i`:
   - If y2 > y1, skip because the condition for forming a valid pair is not met.
   - Otherwise, if y2 is greater than the current "bestY" seen so far for that i,
     count it as a valid pair and update bestY.
3. Return the total count of valid pairs.

Intuition:
We want pairs `(i, j)` such that:
- x1 <= x2
- y1 >= y2
By sorting in the described order, we ensure that once we fix a point `i`,
all valid `j` points appear after it, and we just need to filter by the y condition.
We also use `bestY` to avoid counting dominated points more than once.

Time Complexity: O(n^2) → Sorting takes O(n log n), and the nested loops check all pairs in worst case.
Space Complexity: O(1) → Aside from sorting overhead, we only use a few variables.
*/

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        // Custom comparator for sorting
        auto cmp = [](vector<int> &p1, vector<int> &p2){
            if(p1[0] == p2[0])
                return p1[1] > p2[1];  // if x is same, sort by y descending
            return p1[0] < p2[0];      // otherwise sort by x ascending
        };

        sort(points.begin(), points.end(), cmp);

        int res = 0;

        // Iterate over all pairs (i, j) with i < j
        for(int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int bestY = INT_MIN; // track the best y seen so far for this i

            for(int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                // Only consider if y2 <= y1
                if(y2 > y1)
                    continue;

                // Count if y2 improves the bestY seen so far
                if(y2 > bestY) {
                    res++;
                    bestY = y2;
                }
            }
        }   

        return res;
    }
};
