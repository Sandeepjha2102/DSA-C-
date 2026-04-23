class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;

        int maxLeft = 0;
        int maxRight = 0;
        int totalWater = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(maxLeft < height[left]) maxLeft = height[left];
                else totalWater += maxLeft - height[left];
                left++;
            }
            else{
                if(maxRight < height[right]) maxRight = height[right];
                else totalWater += maxRight - height[right];
                right--;
            }
        }
        return totalWater;
    }
};