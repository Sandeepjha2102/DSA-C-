class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //initialize answer vector
        vector<int> ans(nums.size(), 0);

        //calculate whole array product
        int product = 1;
        for(int i=0; i<nums.size(); i++){
            product *= nums[i];
        }

        int product_without_zero = 1;
        int zero_count = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == 0){
                zero_count++;
                continue;
            }
            product_without_zero *= nums[i];
        }

        // int prefix = 1;
        // int suffix = product;

        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[i] == 0){
        //         suffix = product;
        //     }
        //    else suffix = suffix / nums[i];
        //    ans[i] = (suffix*prefix);
        //    prefix *= nums[i];
        // }

        for(int i =0; i<nums.size(); i++){
            if(nums[i] != 0){
                if(zero_count > 0){
                    ans[i] = 0;
                }
                else{
                    ans[i] = product / nums[i];
                }
            }
            else{
                if(zero_count > 1){
                    ans[i] = 0;
                }
                else{
                    ans[i] = product_without_zero;
                }
            }
        }

        return ans;
    }
};