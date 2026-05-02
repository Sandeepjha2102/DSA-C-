class Solution {
public:

    bool isGood(int i ){
        bool changes = false;
        while (i > 0) {
            int d = i % 10;
            if(d == 3 || d == 4 || d== 7) return false;
            if(d == 2 || d == 5 || d == 6 || d ==  9) changes = true;
            i = i  / 10;
        }
        return changes;
    }

    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(isGood(i)) count++;
        }
        return count;
    }
};