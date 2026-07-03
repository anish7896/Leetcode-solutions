class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int sum = grid[row][col];
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int k=0;k<4;k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                sum += dfs(nrow, ncol, grid, vis);
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col] == 1 && !vis[row][col]){
                    ans = max(ans, dfs(row, col, grid, vis));
                }
            }
        }
        return ans;
    }
};