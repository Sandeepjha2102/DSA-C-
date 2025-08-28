class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> temp;
        
        // Split string into words
        while (ss >> word) {
            temp.push_back(word);
        }

        // Reverse the words
        reverse(temp.begin(), temp.end());

        // Join words back into a string
        string result;
        for (int i = 0; i < temp.size(); i++) {
            if (i > 0) result += " ";
            result += temp[i];
        }
        return result;
    }
};
