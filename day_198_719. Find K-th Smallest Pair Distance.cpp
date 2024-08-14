/*
719. Find K-th Smallest Pair Distance
Solved
Hard
Topics
Companies
Hint
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
 

Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2
*/

/*
Intuition:
- The problem is about finding the k-th smallest distance between all pairs in an array.
- This is done by counting all pairwise distances and then determining the k-th smallest distance.

Time Complexity:
- The time complexity is O(n^2 + d) where n is the size of the array and d is the maximum difference between elements. The O(n^2) part comes from calculating distances for all pairs, and O(d) for iterating over possible distances to find the k-th smallest.

Space Complexity:
- The space complexity is O(d), where d is the maximum element in the array, because of the distance array.

Approach:
- First, we calculate the pairwise distances and store their frequencies.
- Then, by iterating through the possible distances, we subtract the frequency of each distance from k until k becomes 0 or less, at which point we've found the k-th smallest distance.
*/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        // Find the maximum element in the array
        int maxEle = *max_element(nums.begin(), nums.end());

        // Initialize a vector to store the frequency of distances
        vector<int> dist(maxEle + 1, 0);

        // Calculate the pairwise distances and update the frequency vector
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int d = abs(nums[i] - nums[j]);  // Calculate the distance

                dist[d]++;  // Increment the count of this distance
            }
        }   

        // Iterate through the distances to find the k-th smallest one
        for(int d = 0; d <= maxEle; d++){
            k -= dist[d];  // Subtract the count of distance d from k

            // If k becomes zero or negative, return the current distance d
            if(k <= 0){
                return d;
            }
        }

        return 0;  // In case something goes wrong, though this should never happen
    }
};



/*
Intuition:
- The problem is to find the k-th smallest distance among all possible pairs in an array.
- Instead of explicitly calculating all pairwise distances, we can leverage binary search on the distance itself.
- The key idea is to count how many pairs have a distance less than or equal to a given value using a two-pointer technique.

Time Complexity:
- The time complexity is O(n log(maxDistance) + n log n), where n is the size of the array. O(n log n) comes from sorting the array, and O(n log(maxDistance)) comes from the binary search with the two-pointer method for counting pairs.

Space Complexity:
- The space complexity is O(1) as we are only using a few extra variables.

Approach:
- Sort the array to efficiently count pairs with the two-pointer method.
- Use binary search on the possible distance values (from 0 to the maximum possible distance).
- For each mid value (potential distance), count the number of pairs with distance <= mid.
- Adjust the search range based on whether the count of such pairs is greater than or equal to k.
*/

class Solution {
public:
    // Helper function to count pairs with distance <= D using two-pointer technique
    int countPairs(vector<int> &nums, int D) {
        int n = nums.size();
        int left = 0, right = 1;
        int pairs = 0;

        while (right < n) {
            // Move left pointer to maintain the distance condition
            while (nums[right] - nums[left] > D) {
                left++;
            }

            // Count the number of valid pairs with the current right index
            pairs += right - left;
            right++;
        }

        return pairs;
    }

    // Main function to find the k-th smallest distance pair
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        // Sort the array to facilitate two-pointer technique
        sort(nums.begin(), nums.end());

        int low = 0, high = nums[n - 1] - nums[0];
        int res = 0;

        // Binary search on the possible distances
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count pairs with distance <= mid
            int pairs = countPairs(nums, mid);

            // If pairs count is less than k, we need to search on the higher side
            if (pairs < k) {
                low = mid + 1;
            } 
            // Otherwise, this mid might be the answer, but there could be a smaller one
            else {
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};
