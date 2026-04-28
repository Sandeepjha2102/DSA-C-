class Solution {
public:
    int solve(string s, string t){
        int n = s.size();
        int m = t.size();

        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);

        //nested loop
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1+prev[j-1];
                }
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return curr[m];

    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return solve(s, t);
    }
};