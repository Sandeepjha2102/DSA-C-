class Solution {
public:

    vector<int> getrightMax(vector<int>& height, int& n){
        vector<int> rightMax(n);

        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax;
    }
    
    int left;
    int leftMax = -1;
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightMax = getrightMax(height, n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            left = height[i];
            leftMax = max(leftMax, left);
            int h = min(leftMax, rightMax[i]) - height[i];

            sum += h;
        }
        return sum;
    }
};