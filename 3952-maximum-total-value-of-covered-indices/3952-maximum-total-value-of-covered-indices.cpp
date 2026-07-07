class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int idx, int taken, vector<int>& nums, string& s){
        int n = s.size();
        if(idx>=n) return 0;
        if(dp[idx][taken]!=-1) return dp[idx][taken];
        long long ans = solve(idx+1, 0, nums, s);
        if(s[idx]=='1' && !taken){
            ans = max(ans, 1LL*nums[idx]+solve(idx+1, 0, nums, s));
        }
        if(idx+1<n && s[idx+1]=='1'){
            ans = max(ans, 1LL*nums[idx]+solve(idx+1, 1, nums, s));
        }
        return dp[idx][taken] = ans;
    }
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        dp.assign(n, vector<long long>(2, -1));
        return solve(0, 0, nums, s);
    }
};