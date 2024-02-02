/*
1291. Sequential Digits
Solved
Medium
Topics
Companies
Hint
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
*/

class Solution {
public:
    int length(long long int n){
        int len = 0;
        while(n > 0)
        {
            n /= 10;
            len++;
        }
        return len;
    } 
    vector<int> sequentialDigits(int low, int high) {
        vector<vector<int>> dp;
        dp.push_back({12, 23, 34, 45, 56, 67, 78, 89});
        dp.push_back({123, 234, 345, 456, 567, 678, 789});
        dp.push_back({1234, 2345, 3456, 4567, 5678, 6789});
        dp.push_back({12345, 23456, 34567, 45678, 56789});
        dp.push_back({123456, 234567, 345678, 456789});
        dp.push_back({1234567, 2345678, 3456789});
        dp.push_back({12345678, 23456789});
        dp.push_back({123456789});

        int low_len = length(low)-2;
        
        //cout << low_len << " " << high_len << " " << dp.size() << endl;
        vector<int> ans;

        for(int i=low_len; i<8; i++){
            int row_len = dp[i].size();
            for(int j=0; j<row_len; j++){
                if(dp[i][j] >= low && dp[i][j] <= high)
                    ans.push_back(dp[i][j]);
                
                if(dp[i][j] > high) break;
            }
        }
        return ans;
    }
};

#include <vector>

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        for (int i = 1; i < 9; i++) {
            int num = i;
            for (int j = i + 1; j <= 9; j++) {
                num = num * 10 + j;
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
