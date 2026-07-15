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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraedge = 0;
        for(auto &it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u) == ds.findParent(v)){
                extraedge++;
            }
            else{
                ds.unionByRank(u, v);
            }
        }
        int connected = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i) connected++;
        }
        if(extraedge>=(connected-1)) return connected-1;
        else return -1;
    }
};