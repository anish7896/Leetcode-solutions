class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = 1e9;
        for(int k=1;k*(k+1)/2<=n;k++){
            int points = k*(k+1)/2;
            ans = min(ans, k+1+solve(n-points));
        }
        return dp[n] = ans;
    }
    int minDays(int n) {
        dp.assign(n+1, -1);
        return solve(n)-1;
    }
};