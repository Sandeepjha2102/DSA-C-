class Solution {
public:
    void findSubsets(int ind, vector<int>& ds, vector<vector<int>>& ans,
        vector<int>& nums) {
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i+1, ds, ans, nums);
            ds.pop_back();
        }


        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(0, ds, ans, nums);
        return ans;
    }
};