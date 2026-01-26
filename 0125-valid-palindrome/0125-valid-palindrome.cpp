class Solution {
public:
    bool isPalindrome(string s) {
        string updatedS;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                updatedS += s[i];
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                    updatedS += tolower(s[i]);
                }
            else if(s[i] >= '0' && s[i] <= '9'){
                    updatedS += s[i];
                }    
            else{
                continue;
            }}
        
        int i = 0;
        int j = updatedS.size()-1;

        while (i <= j){
            if(updatedS[i] == updatedS[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};