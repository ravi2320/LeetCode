/*
2064. Minimized Maximum of Products Distributed to Any Store
Solved
Medium
Topics
Companies
Hint
You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
Return the minimum possible x.

 

Example 1:

Input: n = 6, quantities = [11,6]
Output: 3
Explanation: One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.
Example 2:

Input: n = 7, quantities = [15,10,10]
Output: 5
Explanation: One optimal way is:
- The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
- The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
- The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.
Example 3:

Input: n = 1, quantities = [100000]
Output: 100000
Explanation: The only optimal way is:
- The 100000 products of type 0 are distributed to the only store.
The maximum number of products given to any store is max(100000) = 100000.
 

Constraints:

m == quantities.length
1 <= m <= n <= 105
1 <= quantities[i] <= 105
*/

/*
Approach:
1. We are tasked with minimizing the maximum number of products that a store can receive.
2. Binary search is used to find the minimum possible maximum (`mid`) such that it is feasible to distribute products within the constraints.
3. Helper function `isPossible` checks if it's possible to distribute the products such that no store has more than `x` products:
   - It iterates over `quantities` and calculates how many stores would be needed for each product count if the max allowed per store is `x`.
   - If at any point the count of required stores exceeds `n`, it returns false.
4. In `minimizedMaximum`:
   - A binary search is performed between `low` (minimum possible max) and `high` (maximum value in `quantities`).
   - The search narrows the range until the optimal minimized max is found.

Functions:
- `isPossible`: Verifies if the current max can be used to distribute products within `n` stores.
- `minimizedMaximum`: Uses binary search to find the minimum possible max distribution.

Time Complexity:
- `isPossible`: O(m), where `m` is the size of `quantities`.
- `minimizedMaximum`: O(m * log(max_quantity)) due to binary search.

Space Complexity: O(1) for auxiliary space.

*/

class Solution {
public:
    // Helper function to check if it's possible to distribute with max x per store
    bool isPossible(vector<int>& quantities, int x, int n) {
        for(int prod : quantities) {
            // Decrease the store count based on the required stores for the product quantity
            n -= (prod + x - 1) / x; // Same as ceiling division: (prod + x - 1) / x

            if (n < 0) return false; // Not enough stores available
        }
        return true;
    }

    // Function to find the minimized maximum product per store
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1; // Minimum possible value of maximum products per store
        int high = *max_element(quantities.begin(), quantities.end()); // Upper bound

        // Perform binary search
        while (low <= high) {
            long long mid = (low + high) >> 1; // Middle point

            if (isPossible(quantities, mid, n)) {
                high = mid - 1; // Try for a smaller max
            } else {
                low = mid + 1; // Increase the max
            }
        }

        return low; // The minimum feasible max
    }
};
