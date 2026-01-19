class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        int n = s.size();
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(!st.empty() && s[i] == st.top()){
                st.pop();
            }
            else st.push(s[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};