/*
1352. Product of the Last K Numbers
Solved
Medium
Topics
Companies
Hint
Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

 

Example:

Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
 

Constraints:

0 <= num <= 100
1 <= k <= 4 * 104
At most 4 * 104 calls will be made to add and getProduct.
The product of the stream at any point in time will fit in a 32-bit integer
*/

class ProductOfNumbers {
    vector<int> nums;  // Stores prefix products
    int zeroIndex;     // Stores the last position where zero was inserted

public:
    /**
     * Approach:
     * - We maintain a prefix product array `nums` to store cumulative products.
     * - If a zero is encountered, we reset `nums` since any product containing zero is zero.
     * - The `getProduct(k)` function efficiently returns the product of the last `k` elements.
     * 
     * Intuition:
     * - Instead of recalculating the product for each query, we use prefix multiplication.
     * - If there is a zero in the last `k` elements, return `0`.
     * - Otherwise, use `nums.back() / nums[nums.size() - k - 1]` for efficient lookup.
     * 
     * Time Complexity:
     * - `add(num)`: O(1)
     * - `getProduct(k)`: O(1)
     * 
     * Space Complexity:
     * - O(N) (Stores prefix products)
     */

    ProductOfNumbers() {
        nums.clear();
        zeroIndex = -1; // No zero encountered initially
    }
    
    void add(int num) {
        if (num == 0) {
            nums.clear();  // Reset prefix product array
            zeroIndex = nums.size(); // Mark reset point
        } 
        else {
            if (nums.empty()) {
                nums.push_back(num);
            } 
            else {
                nums.push_back(nums.back() * num);
            }
        }
    }
    
    int getProduct(int k) {
        if (k > nums.size()) {
            return 0; // More elements requested than available
        }

        // If zero exists within the last 'k' elements, return 0
        if (zeroIndex != -1 && zeroIndex >= (int)(nums.size() - k)) {
            return 0;
        }

        // Compute the product using prefix array
        return k == nums.size() ? nums.back() : nums.back() / nums[nums.size() - k - 1];
    }
};