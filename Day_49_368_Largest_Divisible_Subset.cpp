/*
368. Largest Divisible Subset
Solved
Medium
Topics
Companies
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/
class Solution {
public:
 
vector<int> largestDivisibleSubset( vector<int>& nums ) {
    
    sort(nums.begin(), nums.end());
    
    int n = nums.size();
    vector<int> subset_length(n, 0);
    vector<int> previous_index(n, 0);
    
    subset_length[0] = 1;
    previous_index[0] = -1;
    
    for(int i = 1; i<n ; i++ ){
        
        subset_length[i] = 1;
        previous_index[i] = -1;
        
        // We want to find best divisor which gives max SL
        for(int j = 0; j < i ; j++){
            if( nums[i] % nums[j] == 0 ){
                if( subset_length[j] + 1 > subset_length[i] ){
                    subset_length[i] = subset_length[j] + 1;
                    previous_index[i] = j;
                }
            }
        }
        
        
    }
    
    int max_subset_length = 0;
    int max_subset_index = -1; // Using first element of array
    // 1 3 6 9
    // We want to find best subset
    for(int i = 0; i<n ; i++ ){
        if( subset_length[i] >= max_subset_length ) {
            max_subset_length = subset_length[i];
            max_subset_index = i;
        }
    }
    
    vector<int> result;
    while( max_subset_index != -1 ){
        result.push_back( nums[max_subset_index] );
        // Update it to previous element
        max_subset_index = previous_index[ max_subset_index ] ;
    }
    
    return result;
}
     
};