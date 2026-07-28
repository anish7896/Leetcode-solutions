class Solution {
public:
    int dp[301][11];
    int solve(int i, int days, vector<int>& jobDifficulty){
        int n = jobDifficulty.size();
        if(days == 1){
            int maxi = 0;
            for(int j=i;j<n;j++){
                maxi = max(maxi, jobDifficulty[j]);
            }
            return maxi;
        }
        if(dp[i][days]!=-1) return dp[i][days];
        int ans = INT_MAX;
        int maxi = jobDifficulty[i];
        for(int j=i;j<=n-days;j++){
            maxi = max(maxi, jobDifficulty[j]);
            int remaining = solve(j+1, days-1, jobDifficulty);
            ans = min(ans, maxi+remaining);
        }
        return dp[i][days] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d) return -1;
        memset(dp, -1, sizeof(dp));
        return solve(0, d, jobDifficulty);
    }
};