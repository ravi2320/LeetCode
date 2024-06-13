/*
2037. Minimum Number of Moves to Seat Everyone
Solved
Easy
Topics
Companies
Hint
There are n seats and n students in a room. You are given an array seats of length n, where seats[i] is the position of the ith seat. You are also given the array students of length n, where students[j] is the position of the jth student.

You may perform the following move any number of times:

Increase or decrease the position of the ith student by 1 (i.e., moving the ith student from position x to x + 1 or x - 1)
Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.

Note that there may be multiple seats or students in the same position at the beginning.

 

Example 1:

Input: seats = [3,1,5], students = [2,7,4]
Output: 4
Explanation: The students are moved as follows:
- The first student is moved from from position 2 to position 1 using 1 move.
- The second student is moved from from position 7 to position 5 using 2 moves.
- The third student is moved from from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.
Example 2:

Input: seats = [4,1,5,9], students = [1,3,2,6]
Output: 7
Explanation: The students are moved as follows:
- The first student is not moved.
- The second student is moved from from position 3 to position 4 using 1 move.
- The third student is moved from from position 2 to position 5 using 3 moves.
- The fourth student is moved from from position 6 to position 9 using 3 moves.
In total, 0 + 1 + 3 + 3 = 7 moves were used.
Example 3:

Input: seats = [2,2,6,6], students = [1,3,2,6]
Output: 4
Explanation: Note that there are two seats at position 2 and two seats at position 6.
The students are moved as follows:
- The first student is moved from from position 1 to position 2 using 1 move.
- The second student is moved from from position 3 to position 6 using 3 moves.
- The third student is not moved.
- The fourth student is not moved.
In total, 1 + 3 + 0 + 0 = 4 moves were used.
 

Constraints:

n == seats.length == students.length
1 <= n <= 100
1 <= seats[i], students[j] <= 100
*/

/*
Intuition:
- The goal is to minimize the total number of moves required to seat all students. 
- By sorting both the seats and students arrays, we can pair the closest available seat to each student, minimizing the total distance each student has to move.

Approach:
1. Sort both the `seats` and `students` arrays.
2. Iterate through the arrays and calculate the total distance by summing up the absolute differences between the corresponding elements of the two arrays.
3. Return the total distance as the result.

Time Complexity:
- O(N log N) for sorting the `seats` and `students` arrays.
- O(N) for calculating the total distance.
- Overall, the time complexity is O(N log N).

Space Complexity:
- O(1) additional space, as the sorting is done in place.

*/

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Sort the seats and students arrays
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int n = seats.size();
        int ans = 0;
        
        // Calculate the total number of moves required
        for (int i = 0; i < n; ++i) {
            ans += abs(seats[i] - students[i]);
        }

        return ans;
    }
};


/*
Intuition:
- To minimize the total number of moves required to seat all students, we can use a max heap (priority queue) to sort both the seats and students in descending order.
- By pairing the largest available seat with the largest student's preferred seat, we can ensure the moves are minimized.

Approach:
1. Use a max heap (priority queue) to store the seats and students, both sorted in descending order.
2. Extract the top element from both heaps (which corresponds to the largest seat and largest student preference).
3. Calculate the absolute difference between these elements and add it to the total moves.
4. Repeat until all elements are processed.
5. Return the total moves as the result.

Time Complexity:
- O(N log N) for inserting elements into the priority queues.
- O(N log N) for extracting elements from the priority queues.
- Overall, the time complexity is O(N log N).

Space Complexity:
- O(N) for the space used by the two priority queues.

*/

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Max heaps to store seats and students in descending order
        priority_queue<int> seat, stud;
        int n = seats.size();
        int ans = 0;

        // Push all elements into the respective heaps
        for(int i = 0; i < n; i++) {
            seat.push(seats[i]);
            stud.push(students[i]);
        }

        // Calculate the total number of moves required
        while(!stud.empty()) {
            ans += abs(seat.top() - stud.top());
            seat.pop();
            stud.pop();
        }

        return ans;
    }
};
