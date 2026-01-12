class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i = 0;
        int minending = nums[0];
        int bestending = nums[0];
        int ans = nums[0];

        for(i = 1; i<nums.size(); i++){
            int v1 = bestending * nums[i];
            int v2 = minending * nums[i];
            int v3 = nums[i];

            minending = min(v1, min(v2,v3));
            bestending = max(v1, max(v2,v3));
            ans = max(ans, max(bestending, minending));
        }
        return ans;
    }
};