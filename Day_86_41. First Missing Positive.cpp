/*
41. First Missing Positive
Solved
Hard
Topics
Companies
Hint
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/

/*
Intuition:
The idea is to mark the presence of positive integers in the array using a boolean array.
We iterate through the array, marking visited[nums[i] - 1] as true if nums[i] is within the range [1, n].
Then, we iterate through the boolean array to find the first index i where visited[i] is false. 
If found, we return i + 1 as the first missing positive integer. If all numbers from 1 to n are present, we return n + 1.

Time Complexity: O(n)
- The algorithm iterates through the given array twice, once to mark the presence of positive integers and once to find the first missing positive integer.

Space Complexity: O(n)
- Additional space is used to store the boolean array to mark the presence of positive integers.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false); // Boolean array to mark presence of positive integers
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0 && nums[i] <= n)
                visited[nums[i] - 1] = true; // Marking presence of positive integer
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i])
                return i + 1; // Returning the first missing positive integer
        }
        
        // If all numbers from 1 to n are present, return n + 1
        return n + 1;
    }
};


/*
Intuition:
1. We first iterate through the array to mark the presence of 1 and handle numbers less than or equal to 0 or greater than n.
2. If 1 is not present, the result is 1.
3. Then, we iterate through the array again, negating the value at the index corresponding to each positive number found.
4. After marking the presence of positive numbers, we iterate through the array to find the first missing positive integer.
5. If all numbers from 1 to n are present, the result is n + 1.

Time Complexity: O(n)
- We perform three iterations over the array, each taking O(n) time.

Space Complexity: O(1)
- We use constant extra space regardless of the size of the input array.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool one = false; // Flag to check if 1 is present
        int n = nums.size(); // Size of the array
        // Step 1: Mark the presence of 1 and handle invalid numbers
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1)
                one = true;
            else if(nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }
        // If 1 is not present, the result is 1
        if(!one) return 1;

        // Step 2: Mark the presence of positive numbers by negating the values
        for(int i = 0; i < n; i++) {
            int x = abs(nums[i]); // Absolute value to avoid negative index access
            if(nums[x-1] > 0) // If the number hasn't been negated
                nums[x-1] = -(nums[x-1]); // Negate the value
        } 

        // Step 3: Find the first missing positive integer
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) // If a positive value is found
                return i + 1; // Return the missing positive integer
        }

        // If all numbers from 1 to n are present, the result is n + 1
        return n + 1;
    }
};
