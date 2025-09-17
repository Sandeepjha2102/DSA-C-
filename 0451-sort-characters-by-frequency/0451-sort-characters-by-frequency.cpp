class Solution {
public:
    string frequencySort(string s) {
        //store all elements in map
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }

        //make pair using vector to sort - (because we cannot sort hashmap directly)
        vector<pair<char,int>> freqChar;
        for(auto [ch,fq] : mpp){
            freqChar.push_back({ch,fq});
        }

        //now sort this vector on basis of frequency

        auto cmp = [&] (pair<char,int> &a, pair<char, int> &b){
            return a.second > b.second;
        };

        sort(freqChar.begin(), freqChar.end(), cmp);

        //storing to ans string
        string ans = "";
        for(auto [ch, fq]: freqChar)
            ans.append(fq, ch);
        return ans;
     }
};