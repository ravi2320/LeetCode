/*
1726. Tuple with Same Product
Solved
Medium
Topics
Companies
Hint
Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

 

Example 1:

Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
Example 2:

Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
All elements in nums are distinct.
*/

/*
Approach:
1. The problem requires finding unique pairs (a, b) and (c, d) such that:
   - a * b = c * d
2. Instead of using a nested loop to check for each product, we use a **hashmap** to store product frequencies.
3. For every unique product, if we find multiple pairs forming the same product, we use **combinations** to count valid tuples.

Intuition:
- Instead of checking all pairs for common products inefficiently, we store occurrences in a hashmap.
- Whenever a product repeats, it means more valid (a, b, c, d) tuples exist.

Time Complexity:
- **O(N²)** due to the nested loop iterating over all unique pairs.
- **O(1)** hashmap operations for inserting and looking up products.

Space Complexity:
- **O(N²)** worst-case storage in hashmap when all pairs have distinct products.
*/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size();
        int tuples = 0;

        // Generate all unique pairs (i, j) and store product frequencies
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                tuples += productCount[product]; // Count how many times this product has appeared
                productCount[product]++; // Store this product occurrence
            }
        }

        // Each valid pair contributes to 8 different tuple arrangements
        return tuples * 8;
    }
};
	
	
/*
Approach:
1. Use an unordered_map to store the frequency of products formed by every unique pair in the array.
2. Iterate through all pairs (i, j) and calculate their product, updating the frequency in the map.
3. For each unique product that appears more than once, count how many ways we can choose two pairs with that product.
4. Since each pair can form 8 different tuples, multiply the result by 8.

Intuition:
- Instead of manually checking and counting tuple pairs, we use a frequency-based approach.
- If a product appears `freq` times, the number of ways to pick two pairs is given by:
  → Combinations formula: (freq * (freq - 1)) / 2
- The final count is multiplied by 8 because each pair contributes to multiple tuple arrangements.

Time Complexity: O(N²)
- We iterate over all unique pairs once (O(N²)) and then process the map entries (O(N)).
- Overall complexity is **O(N²)**.

Space Complexity: O(N²)
- In the worst case, all unique products are stored in the map.
*/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuples = 0;
        unordered_map<int, int> productCount;

        // Step 1: Count product frequencies for all unique pairs
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                productCount[nums[i] * nums[j]]++;
            }
        }

        // Step 2: Compute valid tuples using frequency formula
        for(auto &[product, freq] : productCount) {
            if (freq > 1) { // Only consider products that appear multiple times
                tuples += (freq * (freq - 1)) / 2;
            }
        }

        return tuples * 8; // Each valid pair contributes to 8 different tuples
    }
};