class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        if(t.size() > s.size()) return "";

        //store t value in map
        unordered_map<char,int> mpp;
        for(int i = 0; i<t.size(); i++){
            mpp[t[i]]++;
        }
        int requiredCount = t.size();

        int i=0,j=0;
        int minWindowSize = INT_MAX;
        int start_i = 0;


        //story begin 
        while(j < n){
            if(mpp[s[j]] > 0){
                requiredCount--;
            }
                mpp[s[j]]--;

            while(requiredCount==0){
                int currentWindowSize = j-i+1;
                if(minWindowSize > currentWindowSize){
                    minWindowSize = currentWindowSize;
                    start_i = i;
                }   
                mpp[s[i]]++;

                if(mpp[s[i]] > 0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
       return (minWindowSize == INT_MAX) ? "" : s.substr(start_i, minWindowSize);
    }
};

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         if (t.size() > s.size()) return "";

//         // Use an array instead of unordered_map for a significant speed boost
//         vector<int> mpp(128, 0);
//         for (char c : t) mpp[c]++;

//         int requiredCount = t.size();
//         int i = 0, j = 0;
//         int minWindowSize = INT_MAX;
//         int start_i = 0;

//         while (j < s.size()) {
//             // 1. Expand the window
//             // If the character is needed, decrease the total required count
//             if (mpp[s[j]] > 0) {
//                 requiredCount--;
//             }
//             // Decrement frequency in map (even if it goes negative)
//             mpp[s[j]]--;

//             // 2. Shrink the window when valid
//             while (requiredCount == 0) {
//                 int currentWindowSize = j - i + 1;
//                 if (currentWindowSize < minWindowSize) {
//                     minWindowSize = currentWindowSize;
//                     start_i = i;
//                 }

//                 // Add character back to the map as i moves right
//                 mpp[s[i]]++;
//                 // If it's now > 0, it means we are missing a character required by 't'
//                 if (mpp[s[i]] > 0) {
//                     requiredCount++;
//                 }
//                 i++;
//             }
//             j++;
//         }

//         return (minWindowSize == INT_MAX) ? "" : s.substr(start_i, minWindowSize);
//     }
// };