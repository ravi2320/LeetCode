/*
735. Asteroid Collision
Solved
Medium
Topics
Companies
Hint
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/

/*
Approach:
1. Use a stack (`st`) to manage asteroid collisions:
   - If the asteroid is moving to the right (`x > 0`), push it onto the stack.
   - If the asteroid is moving to the left (`x < 0`), resolve collisions:
     - Remove all smaller right-moving asteroids (`st.back() > 0 && st.back() < abs(x)`).
     - If a collision results in equal sizes (`st.back() == abs(x)`), both asteroids are destroyed.
     - If no collision occurs or the stack is empty, push the left-moving asteroid.

2. Return the remaining asteroids in the stack.

Time Complexity:
- **O(n)**: Each asteroid is pushed and popped from the stack at most once.

Space Complexity:
- **O(n)**: The stack can hold all asteroids in the worst case.

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Stack to manage asteroid collisions

        for (int& x : asteroids) {
            if (x > 0) {
                // Push right-moving asteroid onto the stack
                st.push_back(x);
            } else {
                // Handle collisions for left-moving asteroid
                while (!st.empty() && st.back() > 0 && st.back() < abs(x)) {
                    st.pop_back(); // Remove smaller right-moving asteroids
                }

                if (!st.empty() && st.back() == abs(x)) {
                    st.pop_back(); // Destroy both if they are equal in size
                } else if (st.empty() || st.back() < 0) {
                    st.push_back(x); // Push the left-moving asteroid if no collision
                }
            }
        }

        return st; // Return remaining asteroids after all collisions
    }
};
