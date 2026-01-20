class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                mpp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        // accesing from map
        for (int i = 0; i < nums1.size(); i++) {
            if (mpp.find(nums1[i]) != mpp.end()) {
                ans.push_back(mpp[nums1[i]]);
            } else
                ans.push_back(-1);
        }
        return ans;
    }
};