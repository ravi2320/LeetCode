/*
739. Daily Temperatures
Attempted
Medium
Topics
Companies
Hint
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

//Below code give TLE Error
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        int j = 0;
        for(int i=0; i<n-1; i++)
        {
            int cnt = 0;
            for(j = i+1; j<n; j++)
            {
                cnt++;
                if(temperatures[j] > temperatures[i])
                    break;
            }
            answer[i] = j!=n ? cnt:0;
        }
        return answer;
    }
};

//Below code is optimal solution
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;
        for(int i = n-1; i >= 0; --i)
        {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }

            if(st.empty())
                st.push(i);
            else
            {
                answer[i] = st.top() - i;
                st.push(i);
            }
        }
        return answer;
    }
};