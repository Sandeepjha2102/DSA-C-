class Solution {
public:
    string removeDuplicates(string s, int k) {
    stack<pair<char,int>> st;

    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        
         if(st.empty() || st.top().first != c){
            st.push({c, 1});
        }
        else{
            st.top().second++;
            if(st.top().second == k){
                st.pop();
            }
        } 
    }

    string ans;
    //retreiving data from stack
        while(!st.empty()){
            ans.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};