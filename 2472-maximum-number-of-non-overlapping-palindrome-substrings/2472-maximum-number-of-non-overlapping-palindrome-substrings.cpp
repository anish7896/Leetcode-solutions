class Solution {
public:
    int n;
    int dp1[2001][2001];
    int dp2[2001][2001];
    int palindrome(int i, int j, string& s){
        if(i>=j) return 1;
        if(dp1[i][j] != -1) return dp1[i][j];
        if(s[i]==s[j]) return dp1[i][j] = palindrome(i+1, j-1, s);
        return 0;
    }
    int solve(string& s, int k, int i, int j){
        if(i>=n || j>=n) return 0;
        if(dp2[i][j] != -1) return dp2[i][j];
        if(palindrome(i, j, s)){
            int take = 1 + solve(s, k, j+1, j+k);
            int grow = solve(s, k, i, j+1);
            int slide = solve(s, k, i+1, j+1);
            return dp2[i][j] = max({take, grow, slide});
        }
        int grow = solve(s, k, i, j+1);
        int slide = solve(s, k, i+1, j+1);
        return dp2[i][j] = max({grow, slide});
    }
    int maxPalindromes(string s, int k) {
        n = s.length();
        if(k==1) return n;
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        return solve(s, k, 0, k-1);

    }
};