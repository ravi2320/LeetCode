/*
Solved
Easy
Topics
Companies
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

 

Example 1:

Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
Example 2:

Input: bills = [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.
 

Constraints:

1 <= bills.length <= 105
bills[i] is either 5, 10, or 20.
*/

/*
Intuition:
- The problem is to determine if we can provide change to every customer in line, given that customers pay with either a $5, $10, or $20 bill.
- The strategy is to keep track of the number of $5 and $10 bills we have because these are the only denominations we can use to give change.
- When a customer pays with a $10 bill, we need to give back a $5 bill. If they pay with a $20 bill, the best strategy is to give back one $10 and one $5 bill (if available), or three $5 bills if we don't have a $10 bill.

Time Complexity:
- The time complexity is O(n), where n is the number of customers (size of the bills array). We only traverse the array once.

Space Complexity:
- The space complexity is O(1) because we only use a fixed amount of extra space to store the number of $5 and $10 bills.

Approach:
- Initialize counters for the $5 and $10 bills.
- Iterate through the bills array:
  - For each $5 bill, increment the $5 counter.
  - For each $10 bill, check if we have a $5 bill to give as change; if so, decrement the $5 counter and increment the $10 counter.
  - For each $20 bill, prioritize giving change using one $10 and one $5 bill if possible, otherwise give three $5 bills if available.
  - If at any point we can't provide the correct change, return false.
- If we can give change to all customers, return true.

*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        // Iterate through each bill in the array
        for(int &x : bills) {
            if(x == 5) {
                // If the bill is $5, simply increment the $5 counter
                five++;
            }
            else if(x == 10) {
                // If the bill is $10, we need to give back $5 as change
                if(five > 0) {
                    ten++;
                    five--;
                } else {
                    // If we don't have a $5 bill, return false
                    return false;
                }
            }
            else if(five > 0 && ten > 0) {
                // If the bill is $20 and we have a $10 and a $5, give them as change
                five--, ten--;
            }
            else if(five >= 3) {
                // If we don't have a $10, but have at least three $5 bills, give them as change
                five -= 3;
            }
            else {
                // If we can't give the correct change, return false
                return false;
            }
        }

        // If we managed to give change to all customers, return true
        return true;
    }
};
