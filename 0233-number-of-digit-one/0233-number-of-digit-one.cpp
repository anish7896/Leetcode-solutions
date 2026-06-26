class Solution {
public:
    int dp[11][2][11];
    int solve(string &s, int idx, int tight, int cnt){
        if(idx==s.size()) return cnt;
        if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];
        int limit = (tight == 1 ? s[idx]-'0' : 9);
        int ans = 0;
        for(int i=0;i<=limit;i++){
            int updatecnt = (i==1 ? cnt+1 : cnt);
            ans += solve(s, idx+1, (tight && (i==s[idx]-'0')) , updatecnt);
        }
        return dp[idx][tight][cnt] = ans;
    }   
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve (s, 0, 1, 0);
    }
};