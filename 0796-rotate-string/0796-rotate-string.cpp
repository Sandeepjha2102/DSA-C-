class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string s2 = s + s;
        cout << s2;
        if(s2.find(goal) != string::npos){
            return true;
        }
        return false;
    }
};