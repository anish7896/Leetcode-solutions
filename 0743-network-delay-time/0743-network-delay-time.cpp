class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        set<pair<int, int>> st;
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        st.insert({0, k});
        while(!st.empty()){
            auto it = *(st.begin());
            int u = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto &it : adj[u]){
                int v = it.first;
                int wt = it.second;
                if(dis+wt<dist[v]){
                    if(dist[v]!=1e9) st.erase({dist[v], v});
                    dist[v] = dis+wt;
                    st.insert({dist[v], v});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
        }
        return *max_element(dist.begin()+1, dist.end());
    }
};