class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <3){
            return nums.size();
        }
        int size = nums.size();
        int left = 2;

        for(int right = 2; right < size; right++){
            if(nums[left-2] != nums[right]){
                nums[left] = nums[right];
                left++;
             }
        }
        return left;
    }
};