class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m1 = logs.size();
        int m2 = queries.size();
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1]<b[1];
        });
        vector<pair<int, int>> q;
        for(int i=0;i<m2;i++){
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        unordered_map<int, int> mp;
        int i=0, j = 0;
        vector<int> ans(m2);
        for(auto [time, idx] : q){
            int start = time-x;
            int end = time;
            while(j<m1 && logs[j][1]<=end){
                mp[logs[j][0]]++;
                j++;
            }
            while(i<m1 && logs[i][1]<start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }
            ans[idx] = n-mp.size();
        }
        return ans;
    }
};