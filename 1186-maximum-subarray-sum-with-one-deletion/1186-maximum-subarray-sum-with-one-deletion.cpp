class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int i = 0;
        int onedelete = INT_MIN / 2;
        int nodelete = arr[0];
        int result = arr[0];

        for(i = 1; i<arr.size(); i++){
            //for no delete
            int prevnodelete = nodelete;
            nodelete = max(nodelete+arr[i], arr[i]);

            //for one delete 
    
            onedelete = max(onedelete+arr[i], prevnodelete);

            result = max(result, max(onedelete, nodelete));
        }
        return result;
    }
};