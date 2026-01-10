class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        // int low = 0;
        // int high = s1.size()-1;
        
        // sort(s1.begin(), s1.end());

        // while(high < s2.size()){
        //   string substring = s2.substr(low, s1.size());
        //   sort(substring.begin(), substring.end());
        //     if(substring == s1){
        //         return true;
        //     }
        //         high++;
        //         low++;
        // }
        // return false;


        //SLIDING WINDOW 
        int low = 0;
        int high = 0;

        vector<int> freq_s1(26,0);
        vector<int> freq_s2(26,0);

        for(int i=0; i<s1.size(); i++){
            int idx = s1[i] - 'a';
            freq_s1[idx]++;
        }

        while(high < s2.size()){
            freq_s2[s2[high]-'a']++;

            if(high-low+1 > s1.size()){
                freq_s2[s2[low]-'a']--;
                low++;
            }

            if(freq_s1 == freq_s2){
                return true;
            }
            high++;
        }
        return false;
    }
};