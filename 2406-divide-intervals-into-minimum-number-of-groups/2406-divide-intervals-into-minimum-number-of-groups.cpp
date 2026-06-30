class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> events;
        for(int i=0;i<n;i++){
            events.push_back({intervals[i][0], +1});
            events.push_back({intervals[i][1], -1});
        }
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            if(a.first==b.first)
                return a.second > b.second;   // +1 before -1
            return a.first < b.first;
        });
        int overlap = 0;
        int maxoverlap = 0;
        for(auto &it : events){
            overlap += it.second;
            maxoverlap = max(maxoverlap, overlap);
        }
        return maxoverlap;
    }
};