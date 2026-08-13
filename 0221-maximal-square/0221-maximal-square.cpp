class Solution {
public:
    int dp[301][301];
    int solve(int i, int j, vector<vector<char>>& matrix){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(matrix[i][j]=='0') return dp[i][j] = 0;
        return dp[i][j] = 1 + min({solve(i, j-1, matrix), solve(i-1, j, matrix), solve(i-1, j-1, matrix)});

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int maxSide = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    maxSide = max(maxSide, solve(i, j, matrix));
                }
            }
        }
        return maxSide*maxSide;
    }
};