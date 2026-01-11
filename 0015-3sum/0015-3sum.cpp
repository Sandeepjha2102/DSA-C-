class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size();
        int sum = 0;
        vector<vector<int>> ans;
        int i = 0;

        for (i = 0; i < size - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]){
               continue;
            }
            int left = i + 1;
            int right = size - 1;
            int sum = -1 * nums[i];

            while (left < right) {
                int req_sum = nums[left] + nums[right];

                if (sum == req_sum) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }

                else if (req_sum < sum) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};