/*
2751. Robot Collisions
Solved
Hard
Topics
Companies
Hint
There are n 1-indexed robots, each having a position on a line, health, and movement direction.

You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

Note: The positions may be unsorted.

 
 

Example 1:



Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].
Example 2:



Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
Output: [14]
Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].
Example 3:



Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
Output: []
Explanation: Robot 1 and robot 2 will collide and since both have the same health, they are both removed. Robot 3 and 4 will collide and since both have the same health, they are both removed. So, we return an empty array, [].
 

Constraints:

1 <= positions.length == healths.length == directions.length == n <= 105
1 <= positions[i], healths[i] <= 109
directions[i] == 'L' or directions[i] == 'R'
All values in positions are distinct
*/

/*
 * Intuition:
 * The problem involves determining the healths of robots that survive after collisions. Robots are described by 
 * their positions, initial health, and directions ('R' for right and 'L' for left). Robots moving towards each 
 * other will collide, potentially reducing their healths or causing one or both to be destroyed.
 *
 * Time Complexity: O(n log n), where n is the number of robots.
 *   - Sorting the robots by their positions takes O(n log n).
 *   - Processing each robot in the worst case can involve operations on a stack that still results in O(n).
 * Space Complexity: O(n), where n is the number of robots.
 *   - We use additional vectors and a stack that scale linearly with the number of robots.
 */

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> actualIdx(n);
        iota(actualIdx.begin(), actualIdx.end(), 0); // Initialize with indices from 0 to n-1

        // Lambda function to sort by positions
        auto lambda = [&](int &i, int &j){
            return positions[i] < positions[j];
        };

        sort(actualIdx.begin(), actualIdx.end(), lambda); // Sort indices based on positions

        stack<int> st; // Stack to track robots moving to the right

        for(int &currIdx : actualIdx){
            if(directions[currIdx] == 'R'){
                st.push(currIdx); // Push right-moving robots onto the stack
            }
            else{
                // Process left-moving robots and check for collisions
                while(!st.empty() && healths[currIdx] > 0){
                    int top_idx = st.top();
                    st.pop();

                    if(healths[currIdx] > healths[top_idx]){
                        healths[currIdx] -= 1;
                        healths[top_idx] = 0;
                    }
                    else if(healths[top_idx] > healths[currIdx]){
                        healths[currIdx] = 0;
                        healths[top_idx] -= 1;
                        st.push(top_idx); // Push back the surviving right-moving robot
                    }
                    else{
                        healths[top_idx] = 0;
                        healths[currIdx] = 0;
                    }
                }
            }
        }

        // Collect the healths of surviving robots
        vector<int> res;
        for(int &health : healths){
            if(health != 0){
                res.push_back(health);
            }
        }

        return res;
    }
};
