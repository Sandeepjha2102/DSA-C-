class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int countZero = 0;
        // int countOne = 0;
        // int countTwo = 0;

        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] == 0) countZero++;
        //     else if(nums[i] == 1) countOne++;
        //     else countTwo++;
        // }

        // cout << countZero;
        // cout << countOne;
        // cout << countTwo;

        // for(int i=0; i<countZero; i++){
        //     nums[i] = 0;
        // }
        // for(int i=countZero; i<(countZero+countOne); i++){
        //     nums[i] = 1;
        // }
        // for(int i=(countZero+countOne); i<(countZero+countOne+countTwo); i++){
        //     nums[i] = 2;
        // }


        //DUTCH NATIONAL FLAG
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while(mid <= high){
            if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
            else if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else{
                //best case when mid == 1;
                mid++;
            }
        }
    }
};