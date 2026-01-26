class Solution {
public:

    bool palindrome(string&s , int i, int j ){
        while (i < j){
            if(s[i] != s[j]){
                return false;   
            }
                i++;
                j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        int count = 0;
        while(i <= j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else{
            return palindrome(s, i+1, j) || palindrome(s, i, j-1);
        }
        }
        return true;
    }
};