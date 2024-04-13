/*
84. Largest Rectangle in Histogram
Hard
Topics
Companies
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

/*
Intuition:
- We iterate through each bar of the histogram.
- For each bar, we find the leftmost and rightmost smaller bars, which form the boundaries of the rectangle with the current bar as its height.
- We calculate the area of the rectangle formed by the current bar by multiplying its height with the width (difference between rightmost and leftmost smaller bars).
- We keep track of the maximum area found so far and return it as the result.

Time Complexity: O(n^2)
- In the worst case, for each bar, we traverse to both the left and right sides to find the leftmost and rightmost smaller bars, respectively.
- This results in a time complexity of O(n^2), where n is the number of bars in the histogram.

Space Complexity: O(1)
- The space complexity is constant as we only use a few integer variables to store indices and the result.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        
        // Iterate through each bar of the histogram
        for(int i = 0; i < n; i++){
            int leftSmall = i - 1;
            int rightSmall = i + 1;

            // Find the leftmost smaller bar
            while(leftSmall >= 0 && heights[leftSmall] >= heights[i]){
                leftSmall--;
            }

            // Find the rightmost smaller bar
            while(rightSmall < n && heights[rightSmall] >= heights[i]){
                rightSmall++;
            }
            
            // Calculate the area of the rectangle formed by the current bar
            int temp = (rightSmall - leftSmall - 1) * heights[i];
            
            // Update the maximum area found so far
            ans = max(ans, temp);
        }

        return ans;
    }
};


/*
Intuition:
- We use a stack to efficiently find the nearest smaller elements on the left and right sides of each bar.
- We iterate through each bar of the histogram.
- For each bar, we find the nearest smaller bar to its left and right by using a stack.
- We calculate the area of the rectangle formed by the current bar by multiplying its height with the width (difference between the indices of leftmost and rightmost smaller bars).
- We keep track of the maximum area found so far and return it as the result.

Time Complexity: O(n)
- We perform two passes through the array to find the nearest smaller elements on the left and right sides, respectively.
- Each bar is pushed and popped from the stack at most once.
- Thus, the time complexity is O(n).

Space Complexity: O(n)
- We use two arrays of size n to store the indices of the nearest smaller elements on the left and right sides, respectively.
- Additionally, we use a stack that can store at most n elements.
- Therefore, the space complexity is O(n).
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        int leftSmall[n], rightSmall[n];
        stack<int> st;
        
        // Find the nearest smaller elements on the left side of each bar
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            leftSmall[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        // Find the nearest smaller elements on the right side of each bar
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            rightSmall[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
        
        // Calculate the maximum area rectangle
        for(int i = 0; i < n; i++){
            ans = max(ans, (rightSmall[i] - leftSmall[i] + 1) * heights[i]);
        }
        
        return ans;
    }
};

