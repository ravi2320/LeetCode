/*
2610. Convert an Array Into a 2D Array With Conditions
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

 

Example 1:

Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.
Example 2:

Input: nums = [1,2,3,4]
Output: [[4,3,2,1]]
Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= nums.length
*/

/*

1. In this approach first we count the most occuresd element in input vector
2. we create ans 2d vector and vector of set to store the visited element in input vector for each row
3. we iterate given input vector through for loop
4. under for loop we iterate another for loop till maxOccurence of element to store elemnt for each row
5. if row not contain the element we add it and break the loop
   else
	we find next set where element is not present
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = 0;
        map<int, int> m;
        for(int i : nums)
        {
            m[i]++;
            n = max(n, m[i]);
        }
        vector<vector<int>> ans(n);
        vector<set<int>> s(n);
        
        for(int x : nums)
        {
            for(int i=0; i<n; i++)
            {
                if(s[i].find(x) == s[i].end())
                {
                    ans[i].push_back(x);
                    s[i].insert(x);
                    break;
                }
            }
        }
        return ans;
    }
};


/*

optimal code another approach
1. In this approach, first we add the elements in map, map count occurence of each element
2. we use while loop and iterate map until map becomes empty
3. In while loop another for loop and again iterate map we add element of map in vector and reduce the count
	If count of map element is 0 then we erase the map element
   after for loop we add that vector in answer 2d vector
4. this for loop iterate till all map become empty

*/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = 0;
        unordered_map<int, int> s;
        vector<vector<int>> ans;
        for(int i : nums)
        {
            s[i]++;
        }
        
        while(!s.empty())
        {
            vector<int> row;
            for(auto it = s.begin(); it != s.end(); )
            {
                row.push_back(it->first);
                it->second--;
                if(it->second == 0)
                {
                    it = s.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};