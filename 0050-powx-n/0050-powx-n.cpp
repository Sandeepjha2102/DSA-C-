class Solution {
public:
    double myPow(double x, int n) {
         long long m = abs((long long)n); // prevent overflow
       double ans = 1;
       while(m > 0){
        if(m % 2 == 1){
            ans = ans * x;
            m -= 1;
        }
        else{
            m = m / 2;
            x = x * x;
        }
       }
       if(n < 0 ) return 1.0/ans;
       return ans;
    }
};