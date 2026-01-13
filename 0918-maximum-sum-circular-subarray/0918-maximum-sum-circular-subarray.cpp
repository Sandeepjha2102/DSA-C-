class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int i = 0; 
        int maxpart = nums[0];
        int maxAns = nums[0];

        int minpart = nums[0];
        int minAns = nums[0];
        int circular_result = 0;

        int result = nums[0];

        int nums_sum = 0;
        //sum of whole array
        for(int j = 0; j<nums.size(); j++){
            nums_sum += nums[j];
        }

        //normal kadane
        for(i = 1; i < nums.size(); i++){
            maxpart = max(maxpart+nums[i], nums[i]);
            maxAns = max(maxAns, maxpart);

            minpart = min(minpart+nums[i], nums[i]);
            minAns = min(minAns, minpart);

            // circular_result = nums_sum-minpart;

            // result = max(result, max(maxAns, circular_result));
        }
        if(nums_sum == minAns) return maxAns;

        circular_result = nums_sum-minAns;
        return max(circular_result, maxAns);
     
    }
};