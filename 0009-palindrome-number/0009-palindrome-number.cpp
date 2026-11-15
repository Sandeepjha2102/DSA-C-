class Solution {
public:
    bool isPalindrome(int x) {
        int duplicate = x;
        long long ans = 0;

        while(duplicate > 0){
            int lastdigit = duplicate % 10;
            ans = (ans * 10) + lastdigit;
            duplicate = duplicate / 10;
        }

        if(x == ans) return true;
        return false;
    }
};