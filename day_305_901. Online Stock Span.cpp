/*
901. Online Stock Span
Solved
Medium
Topics
Companies
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
 

Constraints:

1 <= price <= 105
At most 104 calls will be made to next.
*/

/*
Approach:
1. Use a monotonic decreasing stack to keep track of stock prices and their indices.
2. For each new price, remove all prices from the stack that are less than or equal to the current price, as they are not relevant for the span calculation.
3. The span for the current price is the difference between the current index and the index of the next greater price on the left (or -1 if none exists).
4. Push the current price and its index onto the stack for future calculations.

Time Complexity:
- **O(1)** on average per `next()` call, since each price is pushed and popped from the stack at most once.

Space Complexity:
- **O(n)** for the stack, where `n` is the number of calls to `next()`.

*/

class StockSpanner {
    stack<pair<int, int>> st; // Stack to store {price, index}
    int idx; // Tracks the current index
public:
    // Constructor
    StockSpanner() {
        st = stack<pair<int, int>>(); // Initialize an empty stack
        idx = -1; // Start index at -1
    }
    
    // Function to calculate the stock span
    int next(int price) {
        idx += 1; // Increment the index for the current price

        // Remove all prices from the stack that are less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        // Calculate the span for the current price
        int ans = idx - (st.empty() ? -1 : st.top().second);

        // Push the current price and its index onto the stack
        st.push({price, idx});

        return ans; // Return the calculated span
    }
};
