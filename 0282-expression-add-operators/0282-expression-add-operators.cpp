class Solution {
public:
    vector<string> ans;

    vector<string> addOperators(string num, int target) {
        dfs(0, "", 0, 0, num, target);
        return ans;
    }

private:
    void dfs(int i, string path, long resSoFar, long prevNum, string& s, int target) {
        if (i == s.size()) {
            if (resSoFar == target) ans.push_back(path);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (j > i && s[i] == '0') break; // Skip leading zero numbers
            long currNum = stol(s.substr(i, j - i + 1));

            if (i == 0) {
                // First number, no operator
                dfs(j + 1, path + to_string(currNum), currNum, currNum, s, target);
            } else {
                dfs(j + 1, path + "+" + to_string(currNum), resSoFar + currNum, currNum, s, target);
                dfs(j + 1, path + "-" + to_string(currNum), resSoFar - currNum, -currNum, s, target);
                dfs(j + 1, path + "*" + to_string(currNum), resSoFar - prevNum + prevNum * currNum, prevNum * currNum, s, target);
            }
        }
    }
};
