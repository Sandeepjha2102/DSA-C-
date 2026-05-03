class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string s2 = s + s;
        
        for(int i = 0; i < s2.size()-goal.size(); i++){
            if(s2.substr(i, goal.size()) == goal) return true;
        }
        return false;
    }
};