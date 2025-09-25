class Solution {
public:

    void solve(int i, int k, int SumTillNow, int n, vector<int>& subset, vector<vector<int>>& ans){
        if(k==0){
            if(SumTillNow == n){
                ans.push_back(subset);
            }
            return;
        }

        if(i == 10) return;

        //pick
        subset.push_back(i);
        solve(i+1, k-1, SumTillNow + i,n, subset, ans);
        subset.pop_back();

        solve(i+1, k, SumTillNow, n, subset, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        vector<vector<int>> ans;

        solve(1,k,0,n,subset, ans);
        return ans;
    }
};