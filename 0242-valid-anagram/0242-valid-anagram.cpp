class Solution {
public:
    bool isAnagram(string s, string t) {

        // if(s.size() != t.size()){
        //     return false;
        // }

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // for(int i=0; i<s.size(); i++){
        //     if(s[i] != t[i]){
        //         return false;
        //     }
        // }
        // return true;


        if(s.size() != t.size()) return false;

        //storing elements of s string into unordered map
        unordered_map<char,int> mpp;

        //iterate over string s
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
        }

        //compare with t string and decrement the values
        for(int i=0; i<t.size(); i++){
            if(mpp.find(t[i]) != mpp.end()){
                mpp[t[i]]--;
            }
            else{
                return false;
            }
        }

        //iterate over map to check value of keys
        for(auto it : mpp){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};