class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        string concat = s+s;

        int ind = concat.find(goal);
        if(ind == -1){
            return false;
        }
        return true;
    }

};