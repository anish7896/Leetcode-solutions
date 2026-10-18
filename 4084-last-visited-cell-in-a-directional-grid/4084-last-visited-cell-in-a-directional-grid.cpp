class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i=0, j=0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int li = 0, lj = 0;
        while(i>=0 && i<n && j>=0 && j<m && !vis[i][j]){
            vis[i][j] = 1;
            li = i, lj = j;
            if(grid[i][j]=='R') j++;
            else if(grid[i][j]=='L') j--;
            else if(grid[i][j]=='U') i--;
            else if(grid[i][j]=='D') i++;
            
        }
        return {li,lj};
    }
};