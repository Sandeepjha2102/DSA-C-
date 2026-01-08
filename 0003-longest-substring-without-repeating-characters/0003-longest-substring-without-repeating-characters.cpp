class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int res_len = 0;
        int n = s.size();
        unordered_map<char,int> mpp;

        for(int high = 0; high < n; high++){
            mpp[s[high]]++;
            int k = high - low + 1;
            while(mpp.size() < k){
                mpp[s[low]]--;
                if(mpp[s[low]] == 0){
                    mpp.erase(s[low]);
                }
                low++;
                k = high-low+1;
            }
            res_len = max(res_len, high-low+1);
            }
        return res_len;
    }
};