class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj , vector<int>& suspicious, vector<int>& indegree){
        suspicious [node] = 1;
        for(auto &it : adj[node]){
            indegree[it]--;
            if(!suspicious[it]){
                dfs(it, adj, suspicious, indegree);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> suspicious(n, 0);
        vector<int> indegree(n, 0);
        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        dfs(k, adj, suspicious, indegree);
        for(int i=0;i<n;i++){
            if(suspicious[i] && indegree[i]>0){
                vector<int> ans;
                for(int j=0;j<n;j++)
                    ans.push_back(j);
                return ans;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!suspicious[i])
                ans.push_back(i);
        }
        return ans; 
    }
};