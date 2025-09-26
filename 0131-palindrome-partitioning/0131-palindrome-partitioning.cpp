class Solution {
public:

    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    void possiblePartition(int index, string& s, vector<string>& temp, vector<vector<string>>& result){
        if(index == s.size()){
            result.push_back(temp);
            return;
        }

        for(int i = index; i<s.size(); i++){
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                possiblePartition(i+1, s, temp, result);
                temp.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string>temp;

        possiblePartition(0,s,temp,result);

        return result;
        
    }
};