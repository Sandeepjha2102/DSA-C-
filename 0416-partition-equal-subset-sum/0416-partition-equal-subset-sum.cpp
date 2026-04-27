class Solution {
public:

    // bool solve(int ind , vector<int>& nums, int target, vector<vector<int>>& dp){
    //     if(target == 0) return true;
    //     if(ind == 0) return nums[0] == target;

    //     if(dp[ind][target] != -1) return dp[ind][target];

    //     bool notPick = solve(ind-1, nums, target, dp);
    //     bool pick = false;
    //         if(target >= nums[ind]) 
    //         pick = solve(ind-1, nums, target-nums[ind], dp);

    //         return dp[ind][target] =  pick | notPick;
    // }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;
        // vector<vector<int>> dp(n, vector<int>((sum/2)+1, -1));
        // return solve(n-1, nums, sum/2, dp);
        
        int n = nums.size(); 
        vector<vector<bool>> dp(n, vector<bool>((sum/2)+1, false));

        //base cases
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if(nums[0] <= sum/2)
            dp[0][nums[0]] = true;

        //nested loop
        for(int i = 1; i < n; i++){
            for(int target = 1; target <= sum/2; target++){
                bool notPick = dp[i-1][target];
                bool pick = false;
            if(target>= nums[i]) 
            pick = dp[i-1][target-nums[i]];

            dp[i][target] =  pick | notPick;
            }
        }

        return dp[n-1][sum/2];
    }
};