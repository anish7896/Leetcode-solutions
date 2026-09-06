class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        vector<int> groups;
        groups.push_back(speed[0]);
        for(int i=1;i<n;i++){
              if(position[i]-position[i-1]<=distance){
                groups.back() = speed[i];
              }
              else{
                groups.push_back(speed[i]);
              }
        }
        int ans = 0;
        int minSpeed = INT_MAX;
        for(int i=groups.size()-1;i>=0;i--){
            if(groups[i]<=minSpeed){
                ans++;
                minSpeed = groups[i];
            }
        }
        return ans;
    }
};