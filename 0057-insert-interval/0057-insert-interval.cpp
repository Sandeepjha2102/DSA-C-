class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res1;
        // int start = intervals[0][0];
        bool insert = false;
        for(int i = 0; i<intervals.size(); i++){
            if(insert == false && intervals[i][0] >= newInterval[0]){
                res1.push_back({newInterval[0], newInterval[1]});
                insert = true;
            }
            res1.push_back(intervals[i]);
        }
        if(insert == false){
            res1.push_back({newInterval[0], newInterval[1]});
        }


        vector<vector<int>> res2;
        int start1 = res1[0][0];
        int end1 = res1[0][1];

        for(int i = 1; i<res1.size(); i++){
            int start2 = res1[i][0];
            int end2 = res1[i][1];

            if(end1 >= start2){
                end1 = max(end1, end2);
                continue;
            }
            else{
                res2.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }
        res2.push_back({start1, end1});
        return res2;
    }
};