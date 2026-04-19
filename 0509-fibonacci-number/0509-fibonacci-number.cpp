class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        int last = f(n-1, dp);
        int slast = f(n-2, dp);
        return last+slast;
    }

    int fib(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};