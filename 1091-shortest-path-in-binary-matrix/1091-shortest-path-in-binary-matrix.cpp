class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        dist[0][0] = 1;
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            if(row == n-1 && col == n-1) return dis;
            for(int i=0;i<8;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dist[nrow][ncol]>dis+1){
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};