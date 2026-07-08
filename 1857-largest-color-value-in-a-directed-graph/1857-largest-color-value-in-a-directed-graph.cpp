class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                dp[i][colors[i]-'a'] = 1;
            } 
        }
        int cnt = 0, ans = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            ans = max(ans, dp[node][colors[node]-'a']);
            for(auto &it : adj[node]){
                for(int i=0;i<26;i++){
                    dp[it][i] = max(dp[it][i], dp[node][i] + (colors[it]-'a' == i));
                }
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(cnt != n) return -1;
        return ans;
    }
};