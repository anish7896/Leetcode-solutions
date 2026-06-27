class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[101][2][10][2];
    int solve(string &s, int idx, int tight, int prev, int started){
        if(idx==s.size()){
            return started;
        }
        if(dp[idx][tight][prev][started] != -1) return dp[idx][tight][prev][started];
        int limit = (tight == 1 ? s[idx]-'0' : 9);
        int ans = 0;
        for(int i=0;i<=limit;i++){
            if(started == 0 && i==0){
                ans = (ans + solve(s, idx+1, (tight && 0==limit) , prev, 0)) % MOD;
            }
            else if(started == 0 && i>0){
                ans =  (ans + solve(s, idx+1, (tight && i==limit), i, 1)) % MOD;
            }
            else if(abs(i-prev)==1){
                ans = (ans + solve(s, idx+1, (tight && i==limit), i, 1)) % MOD;
            }
        }
        return dp[idx][tight][prev][started] = ans;
    }
    string subtract_one(string &s){
        int n = s.size();
        int i = n-1;
        while(i>=0){
            if(s[i]>'0'){
                s[i] -= 1;
                break;
            }
            else{
                s[i] = '9';
                i--;
            }
        }
        if(s[0]=='0' && s.size()>1) return s.substr(1);
        return s;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        int r = solve(high, 0, 1, 0, 0);
        low = subtract_one(low);
        memset(dp, -1, sizeof(dp));
        int l = solve(low, 0, 1, 0, 0);
        return (r-l+MOD)%MOD;
    }
};