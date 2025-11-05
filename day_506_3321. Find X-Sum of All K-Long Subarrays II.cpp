/*
3321. Find X-Sum of All K-Long Subarrays II
Solved

You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:

Count the occurrences of all elements in the array.
Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
Calculate the sum of the resulting array.
Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

 

Example 1:

Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

Output: [6,10,12]

Explanation:

For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
Example 2:

Input: nums = [3,8,7,8,7,5], k = 2, x = 2

Output: [11,15,15,15,12]

Explanation:

Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].

 

Constraints:

nums.length == n
1 <= n <= 105
1 <= nums[i] <= 109
1 <= x <= k <= nums.length
*/

/*
Intuition:
- We are given an array of integers and need to calculate the sum of elements in a sliding window of size `k`. The sum is weighted by a custom formula based on the frequency of the element in the window.
- The core of the problem revolves around maintaining a set of elements with their frequencies and ensuring that the elements with the highest frequency are kept within the set.
- We use two sets:
  1. `main`: a set that holds the most frequent elements up to size `x`. This set keeps track of the elements in the window, sorted by frequency and their value.
  2. `second`: a set for the elements that are pushed out of `main` when its size exceeds `x`.

Approach:
- We iterate through the array using a sliding window of size `k`.
- As we process each element, we maintain a frequency count and keep track of its sum using the sets.
- When an element is added or removed from the sliding window, we efficiently update both the `main` and `second` sets, ensuring that the invariant of keeping the largest `x` elements is respected.

Time Complexity:
- Each insertion or removal operation into the sets (`main` and `second`) takes logarithmic time in terms of the number of elements, so `O(log x)`. This happens whenever an element enters or leaves the sliding window.
- For each element in the array, we perform these operations. Hence, the time complexity per element is `O(log x)`.
- Overall time complexity is O(n log x), where `n` is the length of the array.

Space Complexity:
- We maintain two sets (`main` and `second`) to hold at most `x` elements. Therefore, the space complexity is O(x) for storing elements in these sets.
- Additionally, we use a frequency map (`mp`), which can store up to `k` unique elements. Hence, space complexity is O(k).

*/

class Solution {
    typedef pair<int, int> P; // Pair of frequency and element
    set<P> main, second; // `main` holds the largest `x` elements by frequency, `second` holds others
    long long sum; // Variable to store the sum of elements in the current window

public:
    // Function to insert a pair (frequency, element) into the appropriate set
    void insertToSet(const P &p, int x) {
        // If the set size is less than x or the current pair is greater than the smallest in `main`, we add it to `main`
        if(main.size() < x || *main.begin() < p) {
            sum += 1LL * p.first * p.second; // Add the product of frequency and element value to the sum
            main.insert(p); // Insert the element into the `main` set

            // If `main` exceeds size `x`, move the smallest element to `second`
            if(main.size() > x) {
                P smallest = *main.begin();
                sum -= 1LL * smallest.first * smallest.second; // Remove its contribution from sum
                main.erase(smallest); // Remove the smallest element
                second.insert(smallest); // Insert it into `second`
            }
        }
        else {
            second.insert(p); // If element doesn't belong to `main`, insert it into `second`
        }
    }

    // Function to remove a pair (frequency, element) from the appropriate set
    void removeFromSet(const P &p, int x) {
        if(main.count(p)) {
            // If the element is in `main`, subtract its contribution from the sum
            sum -= 1LL * p.first * p.second;
            main.erase(p); // Remove it from `main`

            // If `second` has elements, move the largest one back to `main`
            if(second.size() > 0) {
                P largest = *second.rbegin(); // Get the largest element in `second`
                sum += 1LL * largest.first * largest.second; // Add its contribution to the sum
                second.erase(largest); // Remove it from `second`
                main.insert(largest); // Insert it back into `main`
            }
        }
        else {
            second.erase(p); // If the element is in `second`, just remove it
        }
    }

    // Main function to calculate the sum of the elements in the sliding window of size `k`
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        sum = 0; // Initialize sum
        vector<long long> res; // Result vector to store the sums for each window
        
        int i = 0, j = 0; // Two pointers representing the sliding window
        unordered_map<int, int> mp; // Frequency map to count occurrences of each element
        
        while(j < n) {
            // If the current element is already in the window, remove it first from the sets
            if(mp[nums[j]] > 0) {
                removeFromSet({mp[nums[j]], nums[j]}, x);
            }

            // Increment the frequency of the current element
            mp[nums[j]]++;

            // Insert the element into the appropriate set based on its frequency
            insertToSet({mp[nums[j]], nums[j]}, x);

            // If the window size reaches `k`, add the current sum to the result
            if(j - i + 1 == k) {
                res.push_back(sum);

                // Remove the leftmost element from the window
                removeFromSet({mp[nums[i]], nums[i]}, x);
                mp[nums[i]]--; // Decrease its frequency

                // If the frequency of the element becomes zero, remove it from the map
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                else
                    insertToSet({mp[nums[i]], nums[i]}, x); // Otherwise, update its frequency in the set

                i++; // Slide the window
            }

            j++; // Expand the window to the right
        }

        return res; // Return the result vector containing the sums for each window
    }
};
