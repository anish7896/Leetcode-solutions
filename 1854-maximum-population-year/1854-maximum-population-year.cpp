class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<pair<int, int>> events;
        for(int i=0;i<n;i++){
            events.push_back({logs[i][0], +1});
            events.push_back({logs[i][1], -1});
        }
        sort(events.begin(), events.end());
        int curPop = 0;
        int maxPop = 0;
        int year = 2050;
        for(auto &it : events){
            curPop += it.second;
            if(maxPop<curPop){
                maxPop = curPop;
                year = it.first;
            }
        }
        return year;
    }
};