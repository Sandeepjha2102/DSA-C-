class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0; 
        int rightMax = 0; 
        int totalWater = 0; 
        int l = 0;
        int r = n-1;


        while(l <= r){

            if(height[l] <= height[r]){
                if(height[l] >= leftMax){
                    leftMax = height[l];
                }
                else{
                    totalWater += leftMax - height[l];
                }
                l++;
            }

            else{
                if(height[r] >= rightMax){
                    rightMax = height[r];
                }
                else{
                    totalWater += rightMax - height[r];
                }
                r--;
            }
            
        }
        return totalWater;
    }
};