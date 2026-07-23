class Solution {
public:
    bool solve(int i, vector<int>& dp, vector<int>& nums){
        int n = nums.size();
        if(i==n-1) return true;
        if(dp[i]!=-1) return dp[i];
        for(int jump=1;jump<=nums[i];jump++){
            int next = jump + i;
            if(next<n){
                if(solve(next, dp, nums)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, dp, nums);
    }
};