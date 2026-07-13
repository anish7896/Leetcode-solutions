class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!pq.empty()){
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(time>dis[row][col]) continue;
            if(row==n-1 && col==m-1) return time;
            for(int i=0;i<4;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newtime = time+1;
                    // Need to wait
                    if(newtime<grid[nrow][ncol]){
                        if((grid[nrow][ncol]-time)%2 == 0)
                            newtime = grid[nrow][ncol]+1;
                        else
                            newtime = grid[nrow][ncol];
                    }   
                    if(newtime<dis[nrow][ncol]){
                        pq.push({newtime, {nrow, ncol}});
                        dis[nrow][ncol] = newtime;
                    }
                }
            }
        }
        return -1;
    }
};