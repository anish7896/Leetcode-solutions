class Solution {
public:
    int dp[366];
    int solve(int i, vector<int>& days, vector<int>& costs){
        int n = days.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int cost_1 = costs[0] + solve(i+1, days, costs);

        int max_day = days[i]+7;
        int j = i;
        while(j<n && days[j]<max_day) j++;
        int cost_7 = costs[1] + solve(j, days, costs);

        max_day = days[i]+30;
        j = i;
        while(j<n && days[j]<max_day) j++;
        int cost_30 = costs[2] + solve(j, days, costs);

        return dp[i] = min({cost_1, cost_7, cost_30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, days, costs);
    }
};