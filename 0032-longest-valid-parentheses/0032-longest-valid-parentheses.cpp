class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<char> st;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                count++;
                st.push(s[i]);
            }
            else if(st.top() == '(' && s[i] == ')'){
                count++;
                st.pop();
            }
            else{
                count++;
                st.push(s[i]);
            }
        }
        return (count-st.size());
    }
};