/*
1792. Maximum Average Pass Ratio
Solved
Medium
Topics
Companies
Hint
There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
Example 2:

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485
 

Constraints:

1 <= classes.length <= 105
classes[i].length == 2
1 <= passi <= totali <= 105
1 <= extraStudents <= 105
*/

#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
    typedef pair<double, int> P; // Alias for a pair of double (delta) and int (class index)
public:
    /**
     * Approach:
     * - Use a max-heap (priority queue) to always allocate an extra student to the class
     *   that results in the highest gain in average pass ratio.
     * - Calculate the gain in pass ratio for each class after adding one student.
     * - Process the extra students iteratively and update the priority queue.
     *
     * Time Complexity: O((n + extraStudents) * log(n))
     * - O(n log(n)) for initializing the priority queue.
     * - O(extraStudents * log(n)) for updating the priority queue `extraStudents` times.
     *
     * Space Complexity: O(n) for the priority queue.
     */
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<P> pq; // Max-heap to store delta and class index

        // Calculate initial delta for all classes and push into the priority queue
        for (int i = 0; i < n; i++) {
            int pass = classes[i][0], total = classes[i][1];
            double curr_PR = (double)pass / total; // Current pass ratio
            double new_PR = (double)(pass + 1) / (total + 1); // New pass ratio after adding a student
            double delta = new_PR - curr_PR; // Gain in pass ratio
            pq.push({delta, i}); // Push delta and class index
        }

        // Distribute extra students
        while (extraStudents--) {
            P curr = pq.top();
            pq.pop();

            int idx = curr.second; // Get the index of the class with the highest delta
            classes[idx][0]++; // Add a passing student
            classes[idx][1]++; // Increase total students

            // Recalculate delta for the updated class and push back to the priority queue
            int pass = classes[idx][0], total = classes[idx][1];
            double curr_PR = (double)pass / total;
            double new_PR = (double)(pass + 1) / (total + 1);
            double delta = new_PR - curr_PR;
            pq.push({delta, idx});
        }

        // Calculate the final average pass ratio
        double res = 0;
        for (int i = 0; i < n; i++) {
            res += (double)classes[i][0] / classes[i][1];
        }

        return res / n; // Return the average pass ratio
    }
};
