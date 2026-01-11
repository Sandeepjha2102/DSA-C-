class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int size = nums.size();

        vector<int> ans(size);
        int i =0;
        int j = size-1;
        int idx = size-1;

        while(idx >= 0){
            int leftsq = (nums[i] * nums[i]);
            int rightsq = (nums[j] * nums[j]);

            if(leftsq >= rightsq){
                ans[idx] = leftsq;
                i++;
            }
            else{
                ans[idx] = rightsq;
                j--;
            }
            idx--;
        }
        return ans;
    }
};