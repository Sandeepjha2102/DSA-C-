class Solution {
public:

    int solve(vector<int>& nums, int i, int curSum, int target, int maxSum,vector<vector<int>>& dp){
        if(i == nums.size()){
            if(curSum == target) return 1;
            else return 0;
        }

        if(dp[i][curSum+maxSum] != -1) return dp[i][curSum+maxSum];

        int plus = solve(nums, i+1, curSum+nums[i], target, maxSum, dp);
        int minus = solve(nums, i+1, curSum-nums[i], target, maxSum, dp);

        return dp[i][curSum+maxSum] = plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int maxSum = 0;
        for(int i = 0; i < n; i ++){
            maxSum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(2*maxSum+1 , -1));
        return solve(nums, 0, 0, target, maxSum, dp);
    }
};