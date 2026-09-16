class Solution {
public:
    int MOD = 1e9+7;
    int dp[1001][1001];
    int suffix[1001][1001];
    int solve(int n, int k, int i){
        if(k==0) return 1;
        if(i>=n) return 0;
        if(dp[k][i] != -1) return dp[k][i];
        int skip = solve(n,k,i+1);
        int take = getSuffix(n,k-1,i+1);
        
        return dp[k][i] = (take+skip)%MOD;
    }
    int getSuffix(int n, int k, int i){
        if(i>=n) return 0;

        if(suffix[k][i]!=-1) return suffix[k][i];

        return suffix[k][i] = (solve(n,k,i) + getSuffix(n,k,i+1))%MOD;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        memset(suffix,-1,sizeof(suffix));
        return solve(n,k,0);
    }
};