class Solution {
public:
    bool isPalindrome(string s) {
        string updatedString;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                updatedString += tolower(s[i]);
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                updatedString += s[i];
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                updatedString += s[i];
            }
            else{
                continue;
            }
        }
        int n = updatedString.size();
        if(n==0) return true;
        int i = 0;
        int j = n - 1;

        while(i <= j){
            if(updatedString[i] != updatedString[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
        
    }
};