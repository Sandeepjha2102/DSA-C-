class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int res_len = INT_MIN;
        int n = fruits.size();
        unordered_map<int,int> mpp;

        for(int high = 0; high < n; high++){
            mpp[fruits[high]]++;
            while(mpp.size() > 2){
                mpp[fruits[low]]--;
                if(mpp[fruits[low]] == 0){
                    mpp.erase(fruits[low]);
                }
                low++;
            }
                res_len = max(res_len, high-low+1);
        }
        return res_len;
    }
};