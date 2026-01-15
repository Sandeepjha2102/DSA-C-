class NumArray {
   
public:
    vector<int> prefix_sum;

    NumArray(vector<int>& nums) {
        prefix_sum.assign(nums.size()+1, 0);

        for(int i = 0; i<nums.size(); i++){
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right+1] - prefix_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */