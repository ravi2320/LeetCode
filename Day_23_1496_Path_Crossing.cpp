/*
1496. Path Crossing
Solved
Easy
Topics
Companies
Hint
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

 

Example 1:


Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.
Example 2:


Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 

Constraints:

1 <= path.length <= 104
path[i] is either 'N', 'S', 'E', or 'W'.
*/
class Solution {
public:
    bool isPathCrossing(string path) {
    
        unordered_map<char, pair<int, int>> moves;
        moves['N'] = {0, 1};
        moves['S'] = {0, -1};
        moves['E'] = {1, 0};
        moves['W'] = {-1, 0};
        
        unordered_set<string> visited;
        visited.insert("0,0");

        int x = 0, y = 0;

        for(char c:path)
        {
            pair<int, int> curr = moves[c];
            int dx = curr.first;
            int dy = curr.second;

            x += dx;
            y += dy;

            string str = to_string(x) + "," + to_string(y);

            if(visited.find(str) != visited.end())
                return true;

            visited.insert(str);
        }
        return false;
    }
};