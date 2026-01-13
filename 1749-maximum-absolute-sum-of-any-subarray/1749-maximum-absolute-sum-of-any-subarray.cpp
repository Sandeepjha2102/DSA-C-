class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int i = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        int result = abs(nums[0]);

        for(i = 1; i < nums.size(); i++){
            maxSum = max(maxSum + nums[i], (nums[i]));
            minSum = min(minSum + nums[i], nums[i]);
            result = max(abs(result), max(abs(minSum), abs(maxSum)));
        }
        return result;
    }
};