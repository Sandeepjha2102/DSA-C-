class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;
        int sum = 0;
        int result_len = INT_MAX;
        int size = nums.size();

        while(high < size){
            sum = sum + nums[high];
            while(sum >= target){
                int current_len = high-low+1;
                result_len = min(result_len, current_len);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        if(result_len == INT_MAX){
            return 0;
        }
        return result_len;
    }
};