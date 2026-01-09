class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int size = nums.size();
        int low = 0;
        int high = 0;
        int res_len = 0;
        long long product = 1;

        for(high = 0; high < size; high++){
            product *= nums[high];

            while(product >= k){
                product = product / nums[low];
                low++;
            }
            res_len += high-low + 1;
        }
        return res_len;
    }
};