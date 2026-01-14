class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    //     int count = 0;
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++) {
    //         int sum = 0;
    //         for (int j = i; j < n; j++) {
    //             sum += nums[j];
    //             if (sum == k) {
    //                 count += 1;
    //             }
    //         }
    //     }
    //     return count;
    
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int count = 0;

    int n = nums.size();

    for(int i=0; i<n; i++){
        preSum += nums[i];
        int remove = preSum - k;

        count += mpp[remove];
        mpp[preSum] += 1;

    }
    return count;
    
    } 
};