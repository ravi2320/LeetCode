/*
904. Fruit Into Baskets

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/

/*
Approach:
We use the sliding window technique with two pointers (`i` and `j`) and a hashmap to keep track of the count of each fruit type in the current window.
The window is adjusted such that it always contains at most two distinct fruit types.
We keep updating the maximum length of such a window throughout the iteration.

Intuition:
We need to collect fruits from trees in such a way that we only pick two distinct types at most.
This is similar to finding the longest subarray with at most 2 distinct elements.
By using a hashmap to count fruits and a sliding window to track valid subarrays, we can efficiently find the answer.

Time Complexity: O(n)
Each element is processed at most twice (once added, once removed), so the overall time complexity is linear.

Space Complexity: O(1)
The hashmap will store at most 2 fruit types at any time.
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();  // Total number of trees
        unordered_map<int, int> mp;  // To count occurrences of each fruit type in current window
        int i = 0, j = 0, ans = 0;   // Sliding window pointers and answer variable

        // Traverse through the array
        for (int j = 0; j < n; j++) {
            mp[fruits[j]]++;  // Add current fruit to hashmap

            // If more than 2 types of fruits, shrink window from the left
            while (i < j && mp.size() > 2) {
                mp[fruits[i]]--;  // Remove one fruit from the left

                // If a fruit count becomes 0, erase it from the map
                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }

                i++;  // Shrink window from the left
            }

            // Update max window size
            ans = max(ans, j - i + 1);
        }

        return ans;  // Return the maximum length of valid window
    }
};
