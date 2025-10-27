/*
2125. Number of Laser Beams in a Bank
Solved

avatar
Discuss Approach
arrow-up
Medium
Topics
premium lock icon
Companies
Hint
Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

There is one laser beam between any two security devices if both conditions are met:

The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return the total number of laser beams in the bank.

 

Example 1:


Input: bank = ["011001","000000","010100","001000"]
Output: 8
Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
Note that there is no beam between any device on the 0th row with any on the 3rd row.
This is because the 2nd row contains security devices, which breaks the second condition.
Example 2:


Input: bank = ["000","111","000"]
Output: 0
Explanation: There does not exist two devices located on two different rows.
 

Constraints:

m == bank.length
n == bank[i].length
1 <= m, n <= 500
bank[i][j] is either '0' or '1'.
*/

// Intuition:
// The problem asks for the number of laser beams that can be formed between devices in the bank.
// Each string in the `bank` represents a row of devices (where '1' means a device is present and '0' means no device).
// A laser beam can be formed between two devices if there is at least one device in both rows. 
// The number of laser beams formed between two rows is the product of the number of devices in each row.
// As we move through the bank, we calculate the product of the number of devices in the current row and the previous row with devices, and accumulate the total.

 // Time Complexity:
 // - We go through each row (string) in the bank, and for each string, we count the '1's. 
 //   Counting '1's in a string of length `m` takes O(m) time.
 // - Thus, for `n` rows, the time complexity is O(n * m), where `n` is the number of rows and `m` is the average length of the rows.

 // Space Complexity:
 // - We only use a constant amount of extra space (for variables `ans`, `prev`, `cnt`), so the space complexity is O(1).
 
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0; // `ans` stores the total number of laser beams, `prev` tracks the number of devices in the previous row with devices
        
        // Iterate over each row in the bank
        for(string &str : bank) {
            int cnt = 0; // `cnt` tracks the number of devices (i.e., '1's) in the current row
            
            // Count the number of devices (1's) in the current row (string)
            for(char ch : str) {
                if(ch == '1') cnt++;
            }

            // If the current row has at least one device (cnt > 0), calculate the laser beams
            if(cnt > 0){
                ans += cnt * prev;  // Multiply current row's device count with previous row's device count to get the laser beams
                prev = cnt;         // Update `prev` to the current row's device count for the next iteration
            }
        }

        return ans;  // Return the total number of laser beams formed
    }
};
