class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        //base case
        for(int amt =0; amt <= amount; amt++){
            if(amt % coins[0] == 0) 
            dp[0][amt] = amt / coins[0];
            else dp[0][amt] = 1e9;
        }

        //nested loop 
        for(int i = 1; i < n; i++){
            for(int amt = 0; amt <= amount; amt++){
                int notTake = dp[i-1][amt];
                    int take = INT_MAX;
                if(amt >= coins[i]) take = 1 + dp[i][amt-coins[i]];

            dp[i][amt] = min(take, notTake);
            }
        }

        int ans = dp[n-1][amount];
        return (ans >= 1e9 ? -1 : ans);
    }
};