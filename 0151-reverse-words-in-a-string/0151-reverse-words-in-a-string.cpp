class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i=0; i<size; i++){
            string words = "";

            while(i<size && s[i] != ' '){
                words += s[i];
                i++;;
            }
            reverse(words.begin(), words.end());
            if(words.length() > 0 ){
                ans += " " + words;
            }
        }
        return ans.substr(1);

    }
};