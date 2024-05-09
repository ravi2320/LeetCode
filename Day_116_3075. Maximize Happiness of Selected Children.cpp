/*
3075. Maximize Happiness of Selected Children
Solved
Medium
Topics
Companies
Hint
You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.

 

Example 1:

Input: happiness = [1,2,3], k = 2
Output: 4
Explanation: We can pick 2 children in the following way:
- Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
- Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
The sum of the happiness values of the selected children is 3 + 1 = 4.
Example 2:

Input: happiness = [1,1,1,1], k = 2
Output: 1
Explanation: We can pick 2 children in the following way:
- Pick any child with the happiness value == 1. The happiness value of the remaining children becomes [0,0,0].
- Pick the child with the happiness value == 0. The happiness value of the remaining child becomes [0,0].
The sum of the happiness values of the selected children is 1 + 0 = 1.
Example 3:

Input: happiness = [2,3,4,5], k = 1
Output: 5
Explanation: We can pick 1 child in the following way:
- Pick the child with the happiness value == 5. The happiness value of the remaining children becomes [1,2,3].
The sum of the happiness values of the selected children is 5.
 

Constraints:

1 <= n == happiness.length <= 2 * 105
1 <= happiness[i] <= 108
1 <= k <= n
*/


// Intuition:
// - To maximize the happiness sum, we want to choose the k largest happiness values.
// - We sort the happiness vector in non-decreasing order so that the k largest values are at the beginning.
// - We iterate through the first k elements of the sorted vector and calculate the happiness sum.
// - For each element, if the difference between the happiness value and the number of days already removed (cnt) is positive, we add it to the result.
// - Finally, we return the maximum happiness sum.

// Time Complexity: O(NlogN), where N is the size of the happiness vector. Sorting the vector takes O(NlogN) time.
// Space Complexity: O(1), as we only use a constant amount of extra space for variables.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
// Sort the happiness vector in non-decreasing order
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long res = 0; // Initialize the result
        long long cnt = 0; // Initialize a counter

        // Iterate through the first k elements of the sorted happiness vector
        for (int i = 0; i < k; i++) {
            // Calculate the happiness gained by removing up to k days from the beginning
            if (happiness[i] - cnt > 0) {
                res += happiness[i] - cnt;
            }
            cnt++; // Increment the counter
        }

        return res; // Return the maximum happiness sum
    }
};

// Intuition:
// - We can maximize the happiness sum by selecting the k largest happiness values.
// - To efficiently find the k largest values, we can use a max heap (priority queue) to store the happiness values.
// - We insert all the happiness values into the max heap.
// - We pop the top element (largest happiness value) from the heap for each of the k iterations.
// - For each popped element, we calculate the difference between the happiness value and the number of days already removed (cnt).
// - If this difference is positive, we add it to the result. Otherwise, we discard it.
// - Finally, we return the maximum happiness sum.

// Time Complexity: O(NlogN), where N is the size of the happiness vector. Building the max heap takes O(NlogN) time.
// Space Complexity: O(N), where N is the size of the happiness vector. The priority queue requires O(N) space.
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq; // Max heap to store happiness values
        
        // Insert all happiness values into the max heap
        for(int i=0; i<happiness.size(); i++){
            pq.push(happiness[i]);
        }   

        long long res = 0; // Result variable to store maximum happiness sum
        int cnt = 0; // Variable to keep track of the number of days already removed

        // Iterating through the k largest happiness values
        for(int i=0; i<k; i++)
        {
            // Getting the top element (largest happiness value) from the max heap
            // Calculating the difference between the happiness value and the number of days already removed
            if(pq.top() - cnt > 0)
                res += pq.top() - cnt;

            pq.pop(); // Removing the top element (largest happiness value) from the max heap
            cnt++; // Incrementing the number of days already removed
        }

        return res; // Returning the maximum happiness sum
    }
};


