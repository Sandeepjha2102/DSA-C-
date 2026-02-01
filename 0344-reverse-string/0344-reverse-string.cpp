class Solution {
public:
    void reverseStr(int i, vector<char>& s, int n){
        if(i >= n/2){
            return;
        }
        swap(s[i], s[n-i-1]);
        reverseStr(i+1, s, n);
    }

    void reverseString(vector<char>& s) {
        int n = s.size();
        return reverseStr(0, s, n);
    }
};