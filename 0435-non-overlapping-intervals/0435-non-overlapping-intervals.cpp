class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int n = intervals.size();

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for(int i = 1; i < n; i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end1 > start2){
                count += 1;
                end1 = min(end1, end2);
                continue;
            }
            else{
                start1 = start2;
                end1 = end2;
            }
        };
        return count;
    }
};