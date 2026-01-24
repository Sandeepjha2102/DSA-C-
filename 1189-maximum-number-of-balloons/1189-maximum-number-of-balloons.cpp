class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> alpha(26, 0);

        for(int i = 0; i < text.size(); i++){
            char c = text[i];
            alpha[c - 'a']++;
        }


        return min({
            alpha['b' - 'a'],
            alpha['a' - 'a'],
            alpha['l' - 'a']/2,
            alpha['o' - 'a']/2,
            alpha['n' - 'a'],
        });
        
        }
};