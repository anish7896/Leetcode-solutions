class Solution {
public:
    int dp[10][2][1024][2];
    int solve(string &s, int idx, int tight, int mask, int started){
        if(idx==s.size()) return started;
        if(dp[idx][tight][mask][started]!=-1) return dp[idx][tight][mask][started];
        int limit = (tight == 1) ? s[idx]-'0' : 9;
        int ans = 0;
        for(int i=0;i<=limit;i++){
            if(started==0 && i==0){
                ans += solve(s, idx+1, (tight && (0==limit)), mask, 0);
            }
            else{
                if(mask & (1<<i)) continue;
                ans += solve(s, idx+1, (tight && (i==limit)), (mask | (1<<i)), 1);
            }
        }
        return dp[idx][tight][mask][started] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return n-solve(s, 0, 1, 0, 0);
    }
};