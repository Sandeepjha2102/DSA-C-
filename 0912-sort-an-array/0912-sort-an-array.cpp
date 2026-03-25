class Solution {
public:

    void merge(vector<int>& nums, int s, int e){
        int mid = (s+e)/2;
        int len1 = mid-s+1;
        int len2 = e-mid;

        vector<int> first(len1);
        vector<int> second(len2);

        //copy values in first
        int originalIndex = s;
        for(int i = 0; i < len1; i++){
            first[i] = nums[originalIndex++]; 
        }
        //copy value in second
        originalIndex = mid+1;
        for(int i = 0; i<len2; i++){
            second[i] = nums[originalIndex++];
        }

        //merge both array 
        int index1 = 0;
        int index2 = 0;
        originalIndex = s;
        while(index1 < len1 && index2 < len2){
            if(first[index1] < second[index2]){
                nums[originalIndex++] = first[index1++];
            }
            else{
                nums[originalIndex++] = second[index2++];
            }
        }
        while(index1 < len1){
            nums[originalIndex++] = first[index1++];
        }
        while(index2 < len2){
            nums[originalIndex++] = second[index2++];
        }
    }


    void solve(vector<int>& nums, int s, int e ){
        if(s >= e){
            return;
        }
        int mid = (s+e)/2;

        solve(nums, s, mid);
        solve(nums, mid+1, e);


        //now merge both arrays
        merge(nums,s, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        solve(nums, 0, nums.size()-1);
        return nums;
    }
};