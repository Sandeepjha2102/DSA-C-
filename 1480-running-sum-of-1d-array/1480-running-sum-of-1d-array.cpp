class Solution {
public:

    vector<int> runningSum(vector<int>& nums) {
        vector<int> sumAns(nums.size());
        sumAns[0] = nums[0];
       for(int i = 1; i< nums.size(); i++){
        sumAns[i] = sumAns[i-1] + nums[i];
       }
       return sumAns;
    }
};