/*
881. Boats to Save People
Solved
Medium
Topics
Companies
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
 

Constraints:

1 <= people.length <= 5 * 104
1 <= people[i] <= limit <= 3 * 104

*/

// Intuition:
// This class provides a method to find the minimum number of boats needed to rescue people.
// It first sorts the people's weights in ascending order.
// Then, it uses two pointers approach, one starting from the beginning and the other from the end.
// At each step, it checks if the sum of weights of the people at both pointers is less than or equal to the limit.
// If it is, it increments both pointers.
// If not, it decrements the pointer representing the heavier person.
// It continues this process until both pointers meet, counting the number of boats needed along the way.

// Time Complexity: O(N log N)
// - N is the number of people.
// - Sorting the people's weights takes O(N log N) time.
// - The two pointers approach takes linear time O(N).

// Space Complexity: O(1)
// - The algorithm uses only a constant amount of extra space regardless of the input size.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of boats needed to rescue people
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(people.begin(), people.end()); // Sort people's weights in ascending order

        int i = 0, j = n - 1;
        int boats = 0;

        // Two pointers approach
        while (i <= j) {
            // Check if the sum of weights of people at both pointers is less than or equal to the limit
            if (people[i] + people[j] <= limit) {
                i++; // Increment the pointer representing the lighter person
                j--; // Decrement the pointer representing the heavier person
            } else {
                j--; // Decrement the pointer representing the heavier person
            }
            boats++; // Increment the number of boats needed
        }

        return boats; // Return the minimum number of boats needed
    }
};
