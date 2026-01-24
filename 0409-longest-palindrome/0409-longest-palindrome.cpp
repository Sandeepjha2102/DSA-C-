class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        for(int i =0; i < s.size(); i++){
            mpp[s[i]]++;
        }
        bool gotUnique = false;
        int longest = 0;
        for(auto it : mpp){
            int val = it.second;
            if(val % 2 == 0){
                longest += val;
            }
            else{longest += val-1;
                gotUnique = true;
          }      
        }
        if(gotUnique){
         longest += 1; 
         } 
         return longest;
         } 
};