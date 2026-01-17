class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval[0], newInterval[1]});

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int n = intervals.size();

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];


        for(int i = 1; i < n; i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end1 >= start2){
                end1 = max(end1, end2);
                continue;
            }
            else{
                ans.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }
            ans.push_back({start1, end1});
            return ans;
    }
};