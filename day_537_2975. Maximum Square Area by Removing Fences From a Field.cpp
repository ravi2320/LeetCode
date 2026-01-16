/*
2975. Maximum Square Area by Removing Fences From a Field

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.

Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).

Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.

Since the answer may be large, return it modulo 109 + 7.

Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.

 

Example 1:



Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
Output: 4
Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
Example 2:



Input: m = 6, n = 7, hFences = [2], vFences = [4]
Output: -1
Explanation: It can be proved that there is no way to create a square field by removing fences.
 

Constraints:

3 <= m, n <= 109
1 <= hFences.length, vFences.length <= 600
1 < hFences[i] < m
1 < vFences[i] < n
hFences and vFences are unique.
*/

/*
Approach:
---------
1. Add the boundary fences (1 and m / n) to both horizontal and vertical fences.
2. Sort both fence arrays.
3. Compute all possible distances between pairs of horizontal fences
   and store them in a hash set.
4. For vertical fences, compute all possible distances and check
   if the same distance exists in the horizontal distances set.
5. Track the maximum valid distance that exists in both directions.
6. Return the square of that distance modulo 1e9+7.
7. If no common distance exists, return -1.

Intuition:
----------
A square requires equal width and height.
Any two fences define a possible side length.
If a side length exists in both horizontal and vertical directions,
a square can be formed.
We want the maximum such side.

Time Complexity:
----------------
O(H² + V²)
- H = number of horizontal fences
- V = number of vertical fences

Space Complexity:
-----------------
O(H²)
- Storing all horizontal distances in a hash set

*/

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {

        // Add boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        // Sort fence positions
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        const int MOD = 1e9 + 7;

        // Store all possible horizontal distances
        unordered_set<int> widths;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                widths.insert(hFences[j] - hFences[i]);
            }
        }

        int maxSide = 0;

        // Check vertical distances against horizontal distances
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int dist = vFences[j] - vFences[i];
                if (widths.count(dist)) {
                    maxSide = max(maxSide, dist);
                }
            }
        }

        // If no square possible
        if (maxSide == 0)
            return -1;

        // Return area modulo MOD
        return (1LL * maxSide * maxSide) % MOD;
    }
};
