class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixmin(n, 0);
        int mini = nums[n-1];
        suffixmin[n-1] = mini;
        for(int i=n-2;i>=0;i--){
            mini = min(mini, nums[i]);
            suffixmin[i] = mini;
        }
        int maxi = nums[0];
        for(int i=0;i<n;i++){
            maxi = max(maxi, nums[i]);
            int score = maxi-suffixmin[i];
            if(score<=k){
                return i;
            }
        }
        return -1;
    }
};