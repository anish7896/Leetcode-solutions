class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int ans = 0;
        for(int k=0;k<4;k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];
            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || grid[nrow][ncol]==0) ans++;
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col] == 1){
                    perimeter += dfs(row, col, grid);
                    
                }
            }
        }
        return perimeter;
    }
};