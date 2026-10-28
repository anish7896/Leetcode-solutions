class Solution {
public:
    int dp[1000001];
    int MOD = 1e9+7;
    int solve(int i, string& s, int& k){
        int n = s.length();
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return dp[i]=0;
        long long ans = 0;
        long long num = 0;
        for(int j=i;j<n;j++){
            num = (num*10) + (s[j]-'0');
            if(num>k) break;
            ans = (ans + solve(j+1, s, k))%MOD;
        }
        return dp[i] = ans;
    }
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s, k);
    }
};