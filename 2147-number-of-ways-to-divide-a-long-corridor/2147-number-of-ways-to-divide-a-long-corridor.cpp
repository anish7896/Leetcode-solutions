class Solution {
public:
    int MOD = 1e9+7;
    int dp[100001][3];
    long long solve(int i, int seats, string& corridor){
        int n = corridor.size();
        if(i==n){
            if(seats==2) return 1;
            else return 0;
        }
        if(dp[i][seats] != -1) return dp[i][seats];
        if(seats==2){
            if(corridor[i]=='P'){
                return dp[i][seats] = (solve(i+1, 2, corridor)%MOD + solve(i+1, 0, corridor)%MOD)%MOD;
            }
            else{
                return dp[i][seats] = solve(i+1, 1, corridor) % MOD;
            }
        }
        else{
            return dp[i][seats] = solve(i+1, seats+(corridor[i]=='S'), corridor) % MOD;
        }
    }
    int numberOfWays(string corridor) {
        int n = corridor.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, corridor);
    }
};