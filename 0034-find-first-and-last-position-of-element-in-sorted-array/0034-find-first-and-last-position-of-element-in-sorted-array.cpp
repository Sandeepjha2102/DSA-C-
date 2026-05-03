class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int firstOcc = -1;
        int lastOcc = -1;
        //first occurence find
        while(low <= high){
            mid = low + (high-low)/2;
            if(nums[mid] == target){
                firstOcc = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        
        low = 0;
        high = nums.size()-1;

        //last occurence find
        while(low <= high){
            mid = low + (high-low)/2;
            if(nums[mid] == target){
                lastOcc = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        } 

        return {firstOcc, lastOcc};       
    }
};