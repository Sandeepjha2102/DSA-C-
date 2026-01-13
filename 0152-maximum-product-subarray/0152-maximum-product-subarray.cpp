class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i =0;
        int minCase = nums[0];
        int maxCase = nums[0];
        int result = nums[0];


        for(i = 1; i<nums.size(); i++){
            int v1 = minCase * nums[i];
            int v2 = maxCase * nums[i];
            int v3 = nums[i];

            minCase = min(v1, min(v2, v3));
            maxCase = max(v1, max(v2, v3));

            result = max(result, max(minCase, maxCase));
        }
        return result;
    }
};