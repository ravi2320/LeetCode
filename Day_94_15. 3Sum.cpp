/*
15. 3Sum
Solved
Medium
Topics
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

/**
 * Intuition:
 * - We use a set to store unique triplets to avoid duplicates.
 * - Iterate through the input array, considering each element as the first element of the triplet.
 * - Use a hash set to store unique values for the third element.
 * - Iterate through the remaining elements of the array to find pairs whose sum equals the negation of the first element.
 * - If such a pair is found, form a triplet, sort it, and insert it into the set.
 * - Convert the set of triplets into a vector and return it.
 * - Time Complexity: O(n^2), where n is the size of the input array. The nested loops iterate through all possible pairs, and sorting takes O(k log k) time, where k is the size of the triplets set.
 * - Space Complexity: O(k), where k is the number of unique triplets.
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st; // Set to store unique triplets
        
        // Loop through the array to find triplets
        for(int i = 0; i < nums.size(); i++) {
            set<int> hashset; // Hash set to store unique values for the third element
            
            // Iterate through the remaining elements
            for(int j = i + 1; j < nums.size(); j++) {
                int third = -(nums[i] + nums[j]); // Calculate the third element
                
                // If third element is found in the hashset, add the triplet to the set
                if(hashset.find(third) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], third}; // Form the triplet
                    sort(temp.begin(), temp.end()); // Sort the triplet
                    st.insert(temp); // Insert the triplet into the set
                }
                
                hashset.insert(nums[j]); // Insert the current element into the hashset
            }
        }
        
        // Convert the set of unique triplets into a vector and return
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


/**
 * Intuition:
 * - Sort the input array to easily handle duplicates and maintain order.
 * - Iterate through the array and fix one element (nums[i]) as the first element of the triplet.
 * - Use two pointers (j and k) to find the other two elements such that their sum equals -nums[i].
 * - Handle duplicates by skipping identical elements for nums[i], nums[j], and nums[k].
 * - Time Complexity: O(n^2), where n is the size of the input array. The sorting step takes O(n log n), and the nested loop takes O(n^2).
 * - Space Complexity: O(1) additional space excluding the output, as we are not using any data structure to store elements.
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sorting the array

        vector<vector<int>> ans; // Vector to store the result

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) // Skip duplicates
                continue;

            int j = i + 1; // Pointer j starts from next element after nums[i]
            int k = nums.size() - 1; // Pointer k starts from the end of the array

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of three elements
                
                if(sum < 0) {
                    j++; // Move j to the right to increase the sum
                } else if(sum > 0) {
                    k--; // Move k to the left to decrease the sum
                } else {
                    // Found a triplet whose sum is zero
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Skip duplicates
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    
                    j++; // Move j to the right to explore other possible triplets
                    k--; // Move k to the left to explore other possible triplets
                }
            }
        }

        return ans; // Return the final result
    }
};