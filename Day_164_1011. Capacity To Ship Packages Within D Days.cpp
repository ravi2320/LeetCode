/*
1011. Capacity To Ship Packages Within D Days
Solved
Medium
Topics
Companies
Hint
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:

1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500
*/

/*
 * Intuition:
 * The task is to find the minimum capacity of a ship that can ship all the given weights within the specified number of days.
 * This can be solved using binary search on the weight capacity.
 * We need to determine if a given capacity can ship all weights within the allowed number of days.
 *
 * Time Complexity: O(n * log(sum(weights) - max(weights))), where n is the number of weights. Binary search takes log(end - start) and possibleDays takes O(n).
 * Space Complexity: O(1) as we use a constant amount of extra space.
 */

class Solution {
public:
    // Function to determine if it's possible to ship all weights within the given number of days with a specified capacity
    bool possibleDays(vector<int>& weights, int days, int capacity){
        int daysRequired = 1;
        int currentWeight = 0;

        for(int weight : weights){
            if(currentWeight + weight > capacity){
                daysRequired++;
                currentWeight = 0;
            }
            currentWeight += weight;

            if(daysRequired > days)
                return false;
        }

        return true;
    }

    // Function to find the minimum capacity to ship weights within the specified number of days
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int result = end;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(possibleDays(weights, days, mid)){
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return result;
    }
};
