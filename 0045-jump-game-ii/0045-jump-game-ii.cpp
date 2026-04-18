class Solution {
public:
    int jump(vector<int>& nums) {
        int r = 0;
        int jump = 0;
        int farthest = 0;
            
            for(int i = 0; i < nums.size()-1; i++){
                farthest = max(farthest, nums[i] + i);
                if(r == i){
                r = farthest;
                jump = jump + 1;
                } 
        }
        return jump;
    }
};