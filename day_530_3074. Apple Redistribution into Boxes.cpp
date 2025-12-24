/*
3074. Apple Redistribution into Boxes

You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.

 

Example 1:

Input: apple = [1,3,2], capacity = [4,3,1,5,2]
Output: 2
Explanation: We will use boxes with capacities 4 and 5.
It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
Example 2:

Input: apple = [5,5,5], capacity = [2,4,2,7]
Output: 4
Explanation: We will need to use all the boxes.
 

Constraints:

1 <= n == apple.length <= 50
1 <= m == capacity.length <= 50
1 <= apple[i], capacity[i] <= 50
The input is generated such that it's possible to redistribute packs of apples into boxes.
*/

/*
Approach:
---------
We are given:
- apple[i]   → number of apples in the i-th pile
- capacity  → capacities of available boxes

Goal:
-----
Find the minimum number of boxes required to store all apples.

Steps:
------
1. Compute the total number of apples using accumulate.
2. Sort the box capacities in descending order so we always use
   the largest capacity boxes first (greedy approach).
3. Iteratively subtract box capacities from the total apples:
   - Each subtraction uses one box
   - Stop once all apples are stored (sum <= 0)
4. Return the number of boxes used.

Intuition:
----------
To minimize the number of boxes, we should always choose the box
with the maximum capacity available. This greedy strategy ensures
we fill apples using as few boxes as possible.

Time Complexity:
----------------
O(n log n)
- Sorting the capacity array dominates the runtime.

Space Complexity:
-----------------
O(1) extra space
- Sorting is done in-place.

*/

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        // Total number of apples
        int sum = accumulate(apple.begin(), apple.end(), 0);

        // Sort capacities in descending order
        sort(capacity.rbegin(), capacity.rend());

        int cnt = 0;

        // Use boxes greedily from largest capacity
        for (int &cap : capacity) {
            sum -= cap;
            cnt++;

            // Stop once all apples are placed
            if (sum <= 0)
                break;
        }

        return cnt;
    }
};
