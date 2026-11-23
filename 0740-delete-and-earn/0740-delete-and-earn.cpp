class Solution {
public:
    int solve(int i, vector<int>& points, vector<int>& dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = points[i] + solve(i-2, points, dp);
        int skip = solve(i-1, points, dp);
        return dp[i] = max(take, skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> points(maxi+1, 0);
        for(int i=0;i<n;i++){
            points[nums[i]] += nums[i];
        }
        vector<int> dp(maxi+1, -1);
        return solve(maxi, points, dp);
    }
};