class Solution {
public:

    int solve(int i){
        if(i == 0) return 0;
        int remain = solve(i / 10);

        int digit = i % 10;
        int digit_check = 0;

        if(digit == 0 || digit == 1 || digit == 8) digit_check = 0;
        else if(digit == 2 || digit == 5 || digit == 9 || digit == 6) digit_check = 1;
        else return 2;

        if(remain == 2) return 2;

        if(remain == 0 && digit_check == 0) {
            return 0;
        }
        return 1;
    }

    int rotatedDigits(int n) {
     int count = 0;   
     for(int i = 1; i <= n; i++){
        if(solve(i) ==  1) count++; 
     }
     return count;
    }
};