class Solution {
public:
    int MOD = 1e9 + 7;
    long long solve(int i, vector<int>& dp, int n){
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];
        long long notPlaced = solve(i+1, dp, n);
        long long placed = solve(i+2, dp, n);
        return dp[i] = (placed+notPlaced)%MOD;
    }
    int countHousePlacements(int n) {
        vector<int> dp(n, -1);
        long long ans = solve(0, dp, n);
        return (ans * ans) % MOD;
    }
};