class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int low = 0;
        int high = 0;
        int n = s.size();
        int max_freq = 0;
        int res_len = 0;

        for(high = 0; high < n; high++){
            int idx = s[high] - 'A';
            freq[idx]++;
            max_freq = max(max_freq, freq[idx]);

            while((high-low+1) - max_freq > k){
                freq[s[low] - 'A']--;
                low++;
            }
            res_len = max(res_len, (high-low+1));
        }
        return res_len;
    }
};