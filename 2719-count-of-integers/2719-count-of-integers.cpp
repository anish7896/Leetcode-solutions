class Solution {
public:
    int mini, maxi;
    int dp[25][2][410];
    int MOD = 1e9 + 7;
    int solve(string &s, int idx, int tight, int sum){
        if(idx==s.size()){
            if(sum>=mini && sum<=maxi) return 1;
            else return 0;
        }
        if(dp[idx][tight][sum] != -1) return dp[idx][tight][sum];
        int limit = (tight == 1 ? s[idx]-'0' : 9);
        int ans = 0;
        for(int i=0;i<=limit;i++){
            int updatesum = sum + i;
            ans += solve(s, idx+1, (tight && (i==s[idx]-'0')) , updatesum);
            ans %= MOD;
        }
        return dp[idx][tight][sum] = ans;
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
    int count(string num1, string num2, int min_sum, int max_sum) {
        mini = min_sum;
        maxi = max_sum;
        memset(dp, -1, sizeof(dp));
        int r = solve(num2, 0, 1, 0);
        memset(dp, -1, sizeof(dp));
        num1 = subtract_one(num1);
        int l = solve(num1, 0, 1, 0);
        return (r-l+MOD)%MOD;

    }
};