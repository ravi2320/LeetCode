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

// Intuition:
// This solution applies the "trap" or "rainwater trapping" concept. 
// For each element in the array, it calculates the maximum height of the bars to the left and right of the element.
// The amount of water that can be trapped at this position is the minimum of the left and right maximum heights minus the height of the current bar.
// The total amount of trapped water is accumulated by iterating through each element.
// This solution has a time complexity of O(n^2) and a space complexity of O(1).

// Time Complexity: O(n^2)
// The function has two nested loops, each iterating over the height array of size 'n'.
// In the worst case, for each element 'i', the function iterates through all other elements 'j' in the array to find the maximum heights to the left and right.
// This results in a quadratic time complexity.

// Space Complexity: O(1)
// The function uses only a constant amount of extra space, regardless of the size of the input height array.
// Therefore, the space complexity is constant.
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        // Iterate over each element in the height array
        for(int i=1; i<n-1; i++){
            int leftMax = height[0]; // Initialize leftMax with the height of the first bar
            int rightMax = height[n-1]; // Initialize rightMax with the height of the last bar

            // Find the maximum height of bars to the left and right of the current element
            for(int j=1; j<n-1; j++){
                if(j < i && height[j] > leftMax)
                    leftMax = height[j]; // Update leftMax if a taller bar is found to the left
                else if(j > i && height[j] > rightMax)
                    rightMax = height[j]; // Update rightMax if a taller bar is found to the right
            }

            // Calculate the amount of trapped water at the current position and add it to the total
            int trap_water = min(leftMax, rightMax) - height[i];
            ans += (trap_water > 0) ? trap_water : 0; // Avoid negative values by taking the maximum of 0 and trap_water
        }

        return ans; // Return the total trapped water
    }
};


// Intuition:
// This solution improves the previous one by precomputing the maximum height of bars to the left and right of each element using two arrays.
// The leftMax array stores the maximum height of bars to the left of each element, and the rightMax array stores the maximum height of bars to the right.
// After precomputing these values, the function iterates through each element again to calculate the trapped water at each position using the precomputed leftMax and rightMax arrays.
// This approach reduces the time complexity to O(n) by eliminating the nested loops in the previous solution while maintaining a space complexity of O(n).

// Time Complexity: O(n)
// The function iterates through the height array three times, each with linear time complexity.
// Therefore, the overall time complexity is O(n).

// Space Complexity: O(n)
// The function uses two additional arrays of size 'n' to store the maximum heights to the left and right of each element.
// Therefore, the space complexity is O(n).

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n, height[0]); // Initialize leftMax with the height of the first bar
        vector<int> rightMax(n, height[n-1]); // Initialize rightMax with the height of the last bar

        // Precompute the maximum height of bars to the left of each element
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        // Precompute the maximum height of bars to the right of each element
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int ans = 0;

        // Calculate the trapped water at each position using precomputed leftMax and rightMax arrays
        for(int i=1; i<n-1; i++){
            int trap_water = min(leftMax[i-1], rightMax[i+1]) - height[i];

            ans += (trap_water > 0) ? trap_water : 0;
        }

        return ans; // Return the total trapped water
    }
};

// Intuition:
// This solution utilizes the two-pointer approach to efficiently calculate the trapped water between bars.
// It uses two pointers, 'left' and 'right', starting from the leftmost and rightmost bars, respectively.
// The algorithm maintains two variables, 'leftMax' and 'rightMax', which represent the maximum height of bars encountered so far from the left and right sides, respectively.
// The algorithm then iterates through the bars, adjusting the pointers and updating the trapped water based on the current heights and maximum heights encountered.
// By continuously moving the pointers towards each other and updating the maximum heights, the algorithm efficiently computes the trapped water without requiring additional space.

// Time Complexity: O(n)
// The two-pointer approach traverses the height array once from left to right and once from right to left, each with linear time complexity.
// Therefore, the overall time complexity is O(n).

// Space Complexity: O(1)
// The algorithm utilizes only a constant amount of extra space for variables, regardless of the input size.
// Therefore, the space complexity is O(1).

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int res = 0;

        // Two pointers approach
        while(left < right){
            // Check the smaller height between the left and right pointers
            if(height[left] <= height[right]){
                // Update the leftMax if the current height is greater than leftMax
                if(height[left] >= leftMax)
                    leftMax = height[left];
                else
                    // Calculate and add the trapped water between the current bar and leftMax
                    res += leftMax - height[left];
                
                // Move the left pointer to the right
                left++;
            }
            else {
                // Update the rightMax if the current height is greater than rightMax
                if(height[right] >= rightMax)
                    rightMax = height[right];
                else
                    // Calculate and add the trapped water between the current bar and rightMax
                    res += rightMax - height[right];
                
                // Move the right pointer to the left
                right--;
            }
        }

        // Return the total trapped water
        return res;
    }
};

