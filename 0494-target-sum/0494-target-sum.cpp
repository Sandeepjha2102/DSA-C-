class Solution {
public:

    int solve(vector<int>& nums, int i, int curSum, int target){
        if(i == nums.size()){
            if(curSum == target) return 1;
            else return 0;
        }

        int plus = solve(nums, i+1, curSum+nums[i], target);
        int minus = solve(nums, i+1, curSum-nums[i], target);

        return plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
       return solve(nums, 0, 0, target);
    }
};