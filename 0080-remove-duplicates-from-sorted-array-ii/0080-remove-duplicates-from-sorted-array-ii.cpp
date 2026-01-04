class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return size;

        int left = 2;

        for(int right = 2; right < size; right++){
            if(nums[right] != nums[left-2]){
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};