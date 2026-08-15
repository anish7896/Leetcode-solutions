class Solution {
public:
    vector<int> findNGE(vector<int>& nums){
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = n;
            else nge[i] = st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> findNSE(vector<int>& nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPGE(vector<int>& nums){
        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty()) pge[i] = -1;
            else pge[i] = st.top();
            st.push(i);
        }
        return pge;
    }
    vector<int> findPSE(vector<int>& nums){
        int n = nums.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge = findNGE(nums);
        vector<int> nse = findNSE(nums);
        vector<int> pge = findPGE(nums);
        vector<int> pse = findPSE(nums);
        long long minSum = 0, maxSum = 0;
        for(int i=0;i<n;i++){
            long long left = i-pse[i];
            long long right = nse[i]-i;
            minSum += 1LL*nums[i]*left*right;
        }
        for(int i=0;i<n;i++){
            long long left = i-pge[i];
            long long right = nge[i]-i;
            maxSum += 1LL*nums[i]*left*right;
        }
        return maxSum-minSum;

    }
};