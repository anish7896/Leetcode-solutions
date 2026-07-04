class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        int ans = 0;
        int land = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    land++;
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        if(land==0 || land==m*n) return -1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            ans = max(ans, dist);
            for(int k=0;k<4;k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    q.push({{nrow, ncol}, dist+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return ans;
    }
};