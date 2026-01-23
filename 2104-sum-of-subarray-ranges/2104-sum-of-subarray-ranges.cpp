class Solution {
public:
    vector<int> NGR(vector<int>& nums, int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()]  <= nums[i]){
                    st.pop();
                }
                ans[i] = st.empty() ? n : st.top();
                st.push(i);
        }
        return ans;
    }

    vector<int> NGL(vector<int>& nums, int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n ; i++){
            while(!st.empty() && nums[st.top()]  < nums[i]){
                    st.pop();
                }
                ans[i] = st.empty() ? -1 : st.top();
                st.push(i);
        }
        return ans;
    }

    //minimum
    vector<int> NSR(vector<int>& nums, int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()]  >= nums[i]){
                    st.pop();
                }
                ans[i] = st.empty() ? n : st.top();
                st.push(i);
        }
        return ans;
    }

    vector<int> NSL(vector<int>& nums, int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n ; i++){
            while(!st.empty() && nums[st.top()]  > nums[i]){
                    st.pop();
                }
                ans[i] = st.empty() ? -1 : st.top();
                st.push(i);
        }
        return ans;
    }

    long long getMaxSum(vector<int>& nums, int n){

        vector<int> getNGL = NGL(nums, n);
        vector<int> getNGR = NGR(nums, n);
              
        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long ls = i - getNGL[i];
            long long rs = getNGR[i] - i;

            long long totalfreq = ls*rs;
            long long totalSum = totalfreq * nums[i];
            sum += totalSum;
        }
        return sum;
    }


    long long getMinSum(vector<int>& nums, int n){

        vector<int> getNSL =  NSL(nums, n);
        vector<int> getNSR = NSR(nums, n);
        
        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long ls = i - getNSL[i];
            long long rs = getNSR[i] - i;

            long long totalfreq = ls*rs;
            long long totalSum = totalfreq * nums[i];
            sum += totalSum;
        }
        return sum;
    }


    //final 
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();
        return getMaxSum(nums, n) - getMinSum(nums, n);
    }
};