/*
947. Most Stones Removed with Same Row or Column
Solved
Medium
Topics
Companies
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.
*/

/*
**Intuition:**
In this problem, each stone on a 2D plane can be connected to another stone if they share the same row or column. The goal is to remove as many stones as possible such that at least one stone remains in each connected group of stones. This can be modeled using the Disjoint Set Union (DSU) or Union-Find data structure.

**Approach:**
1. **Union-Find Initialization:**
   - Initialize `parent` and `rank` vectors for each stone.
   - Each stone is its own parent initially, and the rank (depth of tree) is 1.

2. **Union Operations:**
   - For each pair of stones, if they share the same row or column, union them into the same group.

3. **Count Unique Groups:**
   - After processing all unions, count the number of unique groups by checking how many stones are their own parent.

4. **Calculate Result:**
   - The result is the total number of stones minus the number of unique groups.

**Time Complexity:** O(N^2) where N is the number of stones (in the worst case).
**Space Complexity:** O(N) for storing parent and rank arrays.
*/

#include <vector>

class Solution {
    std::vector<int> parent, rank;
    int n;

public:
    // Find function with path compression
    int find(int i) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    // Union function with rank optimization
    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else {
                parent[root_i] = root_j;
                rank[root_j]++;
            }
        }
    }

    // Function to remove maximum stones
    int removeStones(std::vector<std::vector<int>>& stones) {
        n = stones.size();
        parent.resize(n);
        rank.resize(n);

        // Initialize parent and rank
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }

        // Union stones that share the same row or column
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    Union(i, j);
                }
            }
        }

        // Count the number of unique groups
        int group = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) {
                group++;
            }
        }

        // Return the maximum number of stones that can be removed
        return n - group;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    int result = sol.removeStones(stones);
    // Expected Output: 5 (We can remove 5 stones and leave 1 in the final group)
    std::cout << "Maximum stones that can be removed: " << result << std::endl;
    return 0;
}
