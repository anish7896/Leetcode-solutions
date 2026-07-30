class Solution {
public:
    int dp[1001][51];
    int solve(int i, int k, vector<int>& nums){
        int n = nums.size();
        if(k==1){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
            }
            return sum;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int sum = 0;
        int ans = INT_MAX;
        for(int j=i;j<=n-k;j++){
            sum += nums[j];
            int cost = max(sum, solve(j+1, k-1, nums));
            ans = min(ans, cost);
        }
        return dp[i][k] = ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, k, nums);
    }
};