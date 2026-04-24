class Solution {
public:

    void solve(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int n){
        if(idx == n){
        ans.push_back(temp);  return;
        }
        
        temp.push_back(nums[idx]);
        solve(idx+1, nums, temp, ans, nums.size());
        temp.pop_back();
        solve(idx+1, nums, temp, ans, nums.size());
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans, nums.size());

        return ans;
    }
};