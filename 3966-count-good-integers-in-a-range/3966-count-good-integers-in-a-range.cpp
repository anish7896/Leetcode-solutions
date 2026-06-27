class Solution {
public:
    long long dp[20][2][10][2];
    int a;
    long long solve(string &s, int idx, int tight, int prev, int started){
        if(idx==s.size()) return started;
        if(dp[idx][tight][prev][started]!=-1) return dp[idx][tight][prev][started];
        long long limit = (tight == 1) ? s[idx]-'0' : 9;
        long long ans = 0;
        for(int i=0;i<=limit;i++){
            if(started==0 && i==0){
                ans += solve(s, idx+1, (tight && i==limit) , 0, 0);
            }
            else if(started==0 && i>0){
                ans += solve(s, idx+1, (tight && i==limit), i, 1);
            }
            else if(abs(i-prev)<=a){
                ans += solve(s, idx+1, (tight && i==limit), i, 1);
            }
        }
        return dp[idx][tight][prev][started] = ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        a = k;
        memset(dp, -1, sizeof(dp));
        string s = to_string(r);
        long long ri = solve(s, 0, 1, 0, 0);
        l = l-1;
        string t = to_string(l);
        memset(dp, -1, sizeof(dp));
        long long li = solve(t, 0, 1, 0, 0);
        return ri-li;
    }
};