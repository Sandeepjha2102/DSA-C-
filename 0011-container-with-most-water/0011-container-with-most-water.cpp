class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxCap = INT_MIN;

        int left = 0;
        int right = height.size()-1;

        int localCap = 0;
        while(left <= right){
            localCap = (right-left) * min(height[left], height[right]);
            maxCap = max(maxCap, localCap);

            if(height[left] <= height[right]){
                left++;
            } 
            else{
                right--;
            }
        }
        return maxCap;
    }
};