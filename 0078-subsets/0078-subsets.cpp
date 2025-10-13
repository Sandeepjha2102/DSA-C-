class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsets = 1<<(nums.size());
        vector<vector<int>> ans;

        for(int num = 0 ; num<subsets; num++){
            vector<int> list;
            for(int j = 0; j < nums.size(); j++){
                if((num & (1<<j))){
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }
        return ans; 
    }
};