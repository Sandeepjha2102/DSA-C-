class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;

        int cnt = 0;
        while(ans > 1){
            if(ans % 2 == 1) cnt += 1;
            ans = ans/2;
        }
        if(ans == 1) cnt+=1;
        return cnt;
    }
};