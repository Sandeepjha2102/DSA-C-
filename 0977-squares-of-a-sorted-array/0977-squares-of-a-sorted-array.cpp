class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();

        //if all numbers are postive
        if(nums[0] >= 0) {
            for(int i=0; i<size; i++){
                nums[i] = nums[i] * nums[i];
            }
        return nums;
        }

        //if all numbers are negative
        if(nums[size-1] <=0){
            for(int i=0; i<size; i++){
                nums[i] = nums[i] * nums[i];
            }
                reverse(nums.begin(), nums.end());
        return nums;
        }

        //if array includes both negative and postive
        //store negative and postive seprately
        vector<int> pos,neg;
        for(int i=0; i<size; i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        //square postive number;
        for(int i=0; i<pos.size();i++){
            pos[i] = pos[i] * pos[i];
        }

        //sqaure negative number;
        reverse(neg.begin(),neg.end());
        for(int i = 0; i<neg.size(); i++){
            neg[i] = neg[i] * neg[i];
        }

        int i = 0;  // i -> positive
        int j = 0;  // j -> negative
        int id = 0;
        vector<int> ans(pos.size() + neg.size());

        while(i < pos.size() && j <neg.size()){
            if(pos[i] <= neg[j]){
                ans[id] = pos[i];
                id++;
                i++;
            }
            else{
                ans[id] = neg[j];
                id++;
                j++;
            }
        }
        while(i < pos.size()){
                ans[id] = pos[i];
                id++;
                i++;
        }

        while(j < neg.size()){
                ans[id] = neg[j];
                id++;
                j++;
        }


        return ans;
    }
};