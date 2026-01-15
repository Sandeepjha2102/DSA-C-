class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int rem = 0;

        unordered_map<int,int> mpp;

        for(int i=0; i<n; i++){
            sum += nums[i];
            rem = sum % k;

            if(rem < 0){
                rem += k;
            }

            if(mpp.find(rem) == mpp.end()){
                mpp[rem] = i;
            }
            else{
                int idx = mpp[rem];
                int len = i-idx;
                if(len >= 2) return true;
            }
        }
        return false;
    }
};