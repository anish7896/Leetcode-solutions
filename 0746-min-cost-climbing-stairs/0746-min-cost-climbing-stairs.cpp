class Solution {
public:
    int solve(int idx, vector<int>& cost, vector<int>& dp){
        int n = cost.size();
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int onesteps = cost[idx] + solve(idx+1, cost, dp);
        int twosteps = cost[idx] + solve(idx+2, cost, dp);
        return dp[idx] = min(onesteps, twosteps);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        int cost0 = solve(0, cost, dp);
        int cost1 = solve(1, cost, dp);
        return min(cost0, cost1);
    }
};