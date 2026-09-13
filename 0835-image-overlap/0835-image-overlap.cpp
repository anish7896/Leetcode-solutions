class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> a;
        vector<pair<int, int>> b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j] == 1){
                    a.push_back({i, j});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img2[i][j] == 1){
                    b.push_back({i, j});
                }
            }
        }
        map<pair<int, int>, int> mp;
        int ans = 0;
        for(auto &it1 : a){
            for(auto &it2 : b){
                int dr = it2.first - it1.first;
                int dc = it2.second - it1.second;
                mp[{dr, dc}]++;
                ans = max(ans, mp[{dr, dc}]);
            }
        }
        return ans;
    }
};