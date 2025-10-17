// class Solution {
// public:

//     double solve(double x, long n){
//         if(n==0){
//             return 1;
//         }
//         if(n % 2 == 0) {
//             return solve(x*x, n/2);
//         }
//         else{
//             return x*solve(x*x, ((n-1)/2));
//         }
//     }

//     double myPow(double x, int n) {
//         long nn = n;
//         if(n<0) return 1/solve(x,-nn);
//         return solve(x,nn);
//     }
// };


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