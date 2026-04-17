class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxAns = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i > maxAns) return false;

            maxAns = max(maxAns, nums[i] + i);
            if(maxAns >= nums.size()) return true;
        }
        return true;
    }
};