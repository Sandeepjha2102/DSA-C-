class Solution {
public:

    int count(vector<int>& nums, int mid){
        int sum = 0;
        int ways = 1;
        int totalSum = mid;

        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] <= totalSum){
                    sum += nums[i];
            }
            else{
                ways++;
                sum = nums[i];
            }
        }
        return ways;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = (low + high) / 2;
            int splitcount = count(nums,mid);

            if(splitcount > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    return low;

    }
};