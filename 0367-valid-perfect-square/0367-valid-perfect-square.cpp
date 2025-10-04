class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        long long low = 0;
        long long high = num/2;

        while(low <= high){
            long long mid = (low + high) / 2;
            long long check = mid*mid;
            if(check == num) return true;
            else if(check > num) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};