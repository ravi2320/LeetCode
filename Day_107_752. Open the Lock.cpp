/*
752. Open the Lock
Solved
Medium
Topics
Companies
Hint
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

 

Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation: We cannot reach the target without getting stuck.
 

Constraints:

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.
*/

// Intuition:
// This class provides a solution to find the minimum number of rotations required to reach a target combination
// from a given starting combination on a lock. Each rotation can be either incrementing or decrementing
// one of the four digits of the combination. The solution employs a breadth-first search (BFS) approach
// to explore all possible combinations until the target combination is reached.

// Time Complexity: O(1)
// - Since the input size is fixed (4 digits for each combination), the time complexity is constant.

// Space Complexity: O(1)
// - Again, the space complexity is constant since the input size is fixed.

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to fill neighbors of a given combination and add them to the queue
    void fillNeighbours(string curr, queue<string> &q, unordered_set<string> &st) {
        for (int i = 0; i < 4; i++) {
            string inc = curr;
            inc[i] = (curr[i] == '9') ? '0' : inc[i] + 1;

            if (st.find(inc) == st.end()) {
                st.insert(inc);
                q.push(inc);
            }

            string dec = curr;
            dec[i] = (curr[i] == '0') ? '9' : dec[i] - 1;

            if (st.find(dec) == st.end()) {
                st.insert(dec);
                q.push(dec);
            }
        }
    }

    // Function to find the minimum number of rotations required to reach the target combination
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());

        string start = "0000";

        if (st.find(start) != st.end())
            return -1;

        int level = 0;
        queue<string> q;
        q.push(start);
        st.insert(start);

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                string curr = q.front();
                q.pop();

                if (curr == target)
                    return level;

                fillNeighbours(curr, q, st);
            }
            level++;
        }

        return -1; // Target combination not found
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    cout << "Minimum rotations required: " << obj.openLock(deadends, target) << endl; // Output: 6
    return 0;
}
