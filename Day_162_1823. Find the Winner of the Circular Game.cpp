/*
1823. Find the Winner of the Circular Game
Solved
Medium
Topics
Companies
Hint
There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.

 

Example 1:


Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
Example 2:

Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
 

Constraints:

1 <= k <= n <= 500
*/

/*
 * Intuition:
 * The problem is a variant of the Josephus problem, where people are arranged in a circle 
 * and every k-th person is eliminated until only one person remains. The goal is to find 
 * the position of the last remaining person.
 * 
 * We use a vector to simulate the circle of people. Starting from the first person, we 
 * repeatedly eliminate the k-th person and update the circle until only one person is left.
 *
 * Time Complexity: O(n * k), where n is the number of people and k is the step count. In each 
 * elimination step, we have to potentially shift elements in the vector.
 * Space Complexity: O(n), where n is the number of people, due to the storage of the vector.
 */

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr; // Vector to store the circle of people

        for (int i = 1; i <= n; i++) {
            arr.push_back(i); // Initialize the circle with people numbered 1 to n
        }

        int i = 0; // Starting index
        while (arr.size() > 1) {
            int idx = (i + k - 1) % arr.size(); // Calculate the index of the k-th person to eliminate
            arr.erase(arr.begin() + idx); // Eliminate the k-th person
            i = idx; // Update the starting index for the next elimination
        }

        return arr[0]; // The last remaining person is the winner
    }
};


/*
 * Intuition:
 * The problem is a variant of the Josephus problem, where people are arranged in a circle 
 * and every k-th person is eliminated until only one person remains. The goal is to find 
 * the position of the last remaining person.
 * 
 * We use a queue to simulate the circle of people. By moving the first k-1 people to the end 
 * of the queue and then removing the k-th person, we simulate the elimination process until 
 * only one person remains.
 *
 * Time Complexity: O(n * k), where n is the number of people and k is the step count. Each 
 * elimination involves O(k) operations in the worst case.
 * Space Complexity: O(n), where n is the number of people, due to the storage of the queue.
 */

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q; // Queue to store the circle of people

        // Initialize the queue with people numbered 1 to n
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        // Continue eliminating people until only one person remains
        while (q.size() > 1) {
            // Move the first k-1 people to the end of the queue
            for (int cnt = 1; cnt <= (k - 1) % q.size(); cnt++) {
                q.push(q.front());
                q.pop();
            }
            // Remove the k-th person
            q.pop();
        }

        // The last remaining person is the winner
        return q.front();
    }
};


/*
 * Intuition:
 * The problem is a variant of the Josephus problem. The task is to find the winner's position in 
 * a circle after repeatedly removing every k-th person until only one person remains. 
 * This can be solved recursively by reducing the problem size step-by-step.
 * 
 * The base case is when there is only one person, who is trivially the winner. 
 * For more than one person, we reduce the circle size by one, find the winner's index 
 * in the reduced circle, and adjust it according to the original circle size.
 * 
 * Time Complexity: O(n), where n is the number of people. The recursive solution solves the problem 
 * for each size from 1 to n.
 * Space Complexity: O(n), due to the recursion stack.
 */

class Solution {
public:
    // Recursive function to find the index of the winner
    int findWinnerIdx(int n, int k) {
        // Base case: only one person is left
        if (n == 1)
            return 0;

        // Recursive case: reduce the problem size by one
        int idx = findWinnerIdx(n - 1, k);

        // Adjust the winner's index according to the original circle size
        idx = (idx + k) % n;

        return idx;
    }

    // Function to find the winner's position
    int findTheWinner(int n, int k) {
        // Find the winner's index and adjust for 1-based indexing
        int res_idx = findWinnerIdx(n, k);
        return res_idx + 1;
    }
};
