class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        effort[0][0] = 0;
        pq.push({0, {0, 0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            if(row==n-1 && col==m-1) return dis;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int neweffort = max(abs(heights[row][col] - heights[nrow][ncol]), dis);
                    if(neweffort<effort[nrow][ncol]){
                        effort[nrow][ncol] = neweffort;
                        pq.push({neweffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};