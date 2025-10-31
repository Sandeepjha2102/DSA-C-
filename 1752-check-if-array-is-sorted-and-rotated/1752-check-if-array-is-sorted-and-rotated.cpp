class Solution {
public:
    bool check(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==1)
    //         return true;

    //     int pos = 1;
    //     while(pos<n && nums[pos] >= nums[pos-1])
    //         pos++;

    //         if(pos==n) return true;
    //         if(nums[pos] > nums[0]) return false;
    //         if(pos==n-1) return true;

    //     pos+=1;

    //     while(pos<n and nums[pos] >= nums[pos-1] and nums[pos] <= nums[0] )
    //         pos++;
    int count = 0;
        int n = nums.size();

        for (int i = 1; i<n; i++){
            if(nums[i-1] > nums[i]){
                count++;
            }
        }
        if(nums[n-1] > nums[0]){
            count++;
        }
        return count<=1;
    }
};