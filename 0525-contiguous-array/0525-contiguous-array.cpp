class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n =nums.size();
        int zero = 0;
        int one = 0;
        int res = 0;

        unordered_map<int,int> mpp;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                zero++;
            }
            else one++;

            int diff = zero - one;

            if(diff == 0){
                res = max(res, i+1);
                continue;
            }

            if(mpp.find(diff) == mpp.end()){
                mpp[diff] = i;
            }
            else{
                int idx = mpp[diff];
                int len = i - idx;
                res = max(res,len);
            }
        }
        return res;
    }
};