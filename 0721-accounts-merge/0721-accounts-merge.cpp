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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToAccount;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                if(emailToAccount.find(email) == emailToAccount.end()){
                    emailToAccount[email] = i;
                }
                else{
                    ds.unionByRank(i, emailToAccount[email]);
                }
            }
        }
        unordered_map<int, vector<string>> mergedEmails;
        for(auto &it : emailToAccount){
            string email = it.first;
            int account = it.second;
            int parent = ds.findParent(account);
            mergedEmails[parent].push_back(email);
        } 
        vector<vector<string>> ans;
        for(auto &it : mergedEmails){
            int account = it.first;
            vector<string> emails = it.second;
            sort(emails.begin(), emails.end());
            vector<string> temp;
            temp.push_back(accounts[account][0]);
            for(auto &email : emails){
                temp.push_back(email);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};