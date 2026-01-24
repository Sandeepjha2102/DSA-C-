class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> note;

        for(int i = 0; i < ransomNote.size(); i++){
            note[ransomNote[i]]++;
        }

        for(int i =0; i < magazine.size(); i++){
            if(note.find(magazine[i]) != note.end()){
                note[magazine[i]]--;
                if(note[magazine[i]] == 0){
                    note.erase(magazine[i]);
                }
            }
        }

        if(note.size() == 0) return true;
        else return false;    
    }
};