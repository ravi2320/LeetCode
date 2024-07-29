/*
1395. Count Number of Teams
Solved
Medium
Topics
Companies
Hint
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 

Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 105
All the integers in rating are unique.
*/

/*
Intuition:
The problem is to find the number of teams of three soldiers that can be formed under the conditions that the ratings of the soldiers in each team are either strictly increasing or strictly decreasing. We iterate over each soldier as the middle soldier in the team and count the number of soldiers on the left and right that are either smaller or larger than the current middle soldier. These counts help determine the number of valid teams for each configuration.

Time Complexity:
The time complexity is O(N^2), where N is the number of soldiers in the `rating` vector. This is because for each soldier considered as the middle soldier, we traverse all soldiers to its left and right to count possible configurations.

Space Complexity:
The space complexity is O(1) as we only use a fixed amount of additional space (counters) regardless of the input size.
*/

class Solution {
public:
    // Function to count the number of valid teams
    int numTeams(vector<int>& rating) {
        int n = rating.size(); // Number of soldiers
        int team = 0; // Counter for the number of valid teams

        // Iterate through each soldier as the middle soldier in the team
        for(int j = 1; j < n - 1; j++){
            int cntSmallerLeft = 0; // Count of soldiers smaller than rating[j] on the left
            int cntLargerLeft = 0; // Count of soldiers larger than rating[j] on the left
            int cntSmallerRight = 0; // Count of soldiers smaller than rating[j] on the right
            int cntLargerRight = 0; // Count of soldiers larger than rating[j] on the right

            // Count smaller and larger soldiers on the left side
            for(int i = 0; i < j; i++){
                if(rating[i] < rating[j]){
                    cntSmallerLeft++;
                }
                else if(rating[i] > rating[j]){
                    cntLargerLeft++;
                }
            }

            // Count smaller and larger soldiers on the right side
            for(int k = j + 1; k < n; k++){
                if(rating[k] < rating[j]){
                    cntSmallerRight++;
                }
                else if(rating[k] > rating[j]){
                    cntLargerRight++;
                }
            }

            // Calculate the number of valid teams with the current soldier as the middle soldier
            team += (cntSmallerLeft * cntLargerRight) + (cntLargerLeft * cntSmallerRight);
        }

        return team; // Return the total number of valid teams
    }
};

