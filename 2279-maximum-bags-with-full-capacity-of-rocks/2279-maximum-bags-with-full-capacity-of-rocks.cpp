class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int ans = 0;
        vector<int> remaining;
        for(int i=0;i<n;i++){
            remaining.push_back(capacity[i]-rocks[i]);
        }
        sort(remaining.begin(), remaining.end());
        for(int i=0;i<n;i++){
            if(remaining[i] == 0) ans++;
            else if(remaining[i] > 0 && additionalRocks >= remaining[i]){
                additionalRocks -= remaining[i];
                ans++;
            }
        }
        return ans;
    }
};