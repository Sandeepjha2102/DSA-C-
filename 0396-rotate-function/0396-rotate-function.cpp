class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0;
        long f = 0;

        //calculating the f(0)
        for(int i = 0; i < n; i++){
            f += nums[i] * i;
            sum += nums[i];
        }
        
        long ans = f;
        //calculating rest with f(0);
        for(int k = 1; k < n; k++){
            f = f + sum - n * nums[n-k];
            ans = max(ans, f);
        }

        return ans;
    }
};