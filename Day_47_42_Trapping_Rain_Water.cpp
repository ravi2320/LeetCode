/*
42. Trapping Rain Water
Solved
Hard
Topics
Companies
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];
        for(int i=1; i<n; i++){
            lmax[i] = max(height[i], lmax[i-1]);
            rmax[n-i-1] = max(height[n-i-1], rmax[n-i]);
        }
        int water = 0;
        for(int i=1; i<n-1; i++){
            water += min(lmax[i], rmax[i]) - height[i];
        }
        return water;
    }
};