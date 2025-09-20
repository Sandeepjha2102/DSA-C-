class Solution {
public:
    int beautySum(string s) {
        int size = s.size();
        int ans = 0;

        for (int i = 0; i < size; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < size; j++) {
                freq[s[j] - 'a']++;


            int maxi = INT_MIN, mini = INT_MAX;
            for (int f : freq) {
                if (f > 0) {
                    maxi = max(f, maxi);
                    mini = min(f, mini);
                }
            }
            ans += (maxi - mini);
                        }
        }
        return ans; 
    }
};