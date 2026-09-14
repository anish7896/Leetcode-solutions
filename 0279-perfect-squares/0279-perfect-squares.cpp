class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(n==0) return 0;
        int ans = 1e9;
        if(dp[n]!=-1) return dp[n];
        for(int k=1;k*k<=n;k++){
            ans = min(ans , 1 + solve(n-k*k)); 
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        dp.assign(n+1, -1);
        return solve(n);
    }
};