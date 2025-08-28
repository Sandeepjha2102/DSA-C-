class Solution {
public:

    bool isAlphaNum(char ch){
        if((ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A' && ch<= 'Z')){
            return 1;
        }
        return 0;
    }

    bool isPalindrome(string s) {
        int low = 0;
        int high = s.length()-1;

        while(low < high){
            if(!isAlphaNum(s[low])){
                low++;
                continue;
            }
            if(!isAlphaNum(s[high])){
                high--;
                continue;
            }

            if(tolower(s[low]) != tolower(s[high])){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};