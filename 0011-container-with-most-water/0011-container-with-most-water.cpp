class Solution {
public:
    int maxArea(vector<int>& height) {
        int localCap = 0;
        int maxCap = INT_MIN;

        int left = 0;
        int right = height.size()-1;

        while(left <= right){
            localCap = min(height[left], height[right]) * (right-left);
            maxCap = max(localCap, maxCap);

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