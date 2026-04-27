class Solution {
public:

    int solve(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        // if(amount == 0) return MinCoins;
        if(ind == 0){
            if(amount % coins[ind] == 0){
                return amount / coins[ind];
            }
            else{
                return 1e9;
            }
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = 0 + solve(ind-1, coins, amount, dp);
        int take = INT_MAX;
        if(amount >= coins[ind]){
            take = 1 + solve(ind, coins, amount-coins[ind], dp);
        }
        return dp[ind][amount] = min(notTake, take);    
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, coins, amount, dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};