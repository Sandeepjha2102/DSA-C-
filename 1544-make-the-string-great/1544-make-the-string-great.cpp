class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        vector<char> ans;
        for(int i=0; i<s.size(); i++){
            if(!st.empty() && abs(st.top() - s[i]) == 32){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return string(ans.begin(), ans.end());

    }   
};