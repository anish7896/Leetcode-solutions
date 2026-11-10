class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        for(int i=0;i<n;i++){
            available.push({servers[i], i});
        }
        vector<int> ans(m);
        long long time = 0;
        for(int i=0;i<m;i++){
            time = max(time, (long long)i);
            while(!busy.empty() && busy.top().first<=time){
                auto [finishtime, freeserver] = busy.top();
                busy.pop();
                available.push({servers[freeserver], freeserver});
            }
            
            if(available.empty()){
                time = busy.top().first;
                while(!busy.empty() && busy.top().first<=time){
                    auto [finishtime, freeserver] = busy.top();
                    busy.pop();
                    available.push({servers[freeserver], freeserver});
                }
            }
            auto [wt, freeserver] = available.top();
            available.pop();
            ans[i] = freeserver;
            busy.push({time+tasks[i], freeserver});
        }
        return ans;
    }
};