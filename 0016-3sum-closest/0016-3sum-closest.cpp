class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int intial_max = INT_MAX;
        int diff, res_Sum;

        for(int i=0 ; i<size-2; i++){
            // if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = size-1;

            while(left < right){ 
                int sum = nums[i] + nums[left] + nums[right];
                diff = abs(target-sum);
                if(diff < intial_max){
                        intial_max = diff;
                        res_Sum = sum;
                    }
                if(sum == target) return sum;

                else if(sum > target){
                    right--;
                    // while(right > 0 && nums[right] == nums[right+1]){
                    //     right--;
                    // } 
                }
                else{
                    left++;
                    // while(left < size && nums[left] == nums[left-1]){
                    //     left++;
                    // }
                }
            }
        }
        return res_Sum;
    }
};