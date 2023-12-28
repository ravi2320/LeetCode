/*
unordered_map<int, int> nextGreater; // Map to store the next greater element for each element in nums2
        stack<int> s;

        // Iterate through nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] > s.top()) {
                s.pop();
            }

            if (!s.empty()) {
                nextGreater[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        // Populate the result vector based on the nextGreater map
        vector<int> result(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            if (nextGreater.count(nums1[i])) {
                result[i] = nextGreater[nums1[i]];
            }
        }

        return result;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr(nums1.size(), -1);
        for(int i=0; i<nums1.size(); i++)
        {
            int idx = -1;
            for(int j=0; j<nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                    idx = j;
                if(idx > -1 && nums1[i] < nums2[j])
                {
                    arr[i] = nums2[j];
                    break;
                }
            }
        }
        return arr;
    }
};
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // Map to store the next greater element for each element in nums2
        stack<int> s;

        // Iterate through nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] > s.top()) {
                s.pop();
            }

            if (!s.empty()) {
                nextGreater[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        // Populate the result vector based on the nextGreater map
        vector<int> result(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            if (nextGreater.count(nums1[i])) {
                result[i] = nextGreater[nums1[i]];
            }
        }

        return result;
    }
};