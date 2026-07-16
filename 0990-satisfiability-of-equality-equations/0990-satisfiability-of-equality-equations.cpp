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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        for(auto &it : equations){
            if(it[1]=='='){
                int u = it[0]-'a';
                int v = it[3]-'a';
                ds.unionByRank(u, v);
            }
        }
        for(auto &it : equations){
            if(it[1]=='!'){
                int u = it[0]-'a';
                int v = it[3]-'a';
                int pu = ds.findParent(u);
                int pv = ds.findParent(v);
                if(pu==pv) return false;
            }
        }
        return true;
    }
};