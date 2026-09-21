class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for(int i=0;i<n;i++){
            vector<long long> newdp(k, 0);
            newdp[nums[i]%k]++;
            for(int r=0;r<k;r++){
                if(dp[r]>0){
                    int newr = (1LL*r*nums[i])%k;
                    newdp[newr] += dp[r];
                }
            }
            for(int r=0;r<k;r++){
                ans[r] += newdp[r];
            }
            dp = newdp;
        }
        return ans;
    }
};