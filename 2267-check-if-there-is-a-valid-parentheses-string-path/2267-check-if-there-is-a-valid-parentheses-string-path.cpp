class Solution {
public:
    int dp[101][101][201];
    bool solve(int i, int j, int openCount, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        openCount += (grid[i][j]=='(') ? +1 : -1;
        if(openCount<0) return false;
        if(dp[i][j][openCount] != -1) return dp[i][j][openCount];
        if(i==n-1 && j==m-1)  return dp[i][j][openCount] = (openCount==0);
        if(i+1<n){
            if(solve(i+1, j, openCount, grid)) return dp[i][j][openCount] = true;
        }
        if(j+1<m){
            if(solve(i, j+1, openCount, grid)) return dp[i][j][openCount] = true;
        }
        return dp[i][j][openCount] = false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==')' || grid[n-1][m-1]=='(') return false;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, grid);
    }
};