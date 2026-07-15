class DisjointSet{
    public:
        vector<int> parent, rank;
        DisjointSet(int n){
            parent.resize(n);
            rank.resize(n, 0);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = findParent(parent[node]);
        }
        void unionByRank(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu==pv) return;
            if(rank[pu]<rank[pv]){
                parent[pu] = pv;
            }
            else if(rank[pv]<rank[pu]){
                parent[pv] = pu;
            }
            else{
                parent[pu] = pv;
                rank[pv]++;
            }
        }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int wt = abs(x1-x2) + abs(y1-y2);
                edges.push_back({wt, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(n);
        int cost = 0;
        for(auto &it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findParent(u) != ds.findParent(v)){
                cost += wt;
                ds.unionByRank(u, v);
            }
        }
        return cost;
    }
};