class Solution {
public:
    double dp[101][101];
    double solve(int i, int k, vector<int>& nums){
        int n = nums.size();
        if(k==1){
            double sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
            }
            return sum/(n-i);
        }
        if(dp[i][k] != -1) return dp[i][k];
        double sum = 0;
        double ans = 0;
        for(int j=i;j<=n-k;j++){
            sum += nums[j];
            double score = sum/(j-i+1) + solve(j+1, k-1, nums);
            ans = max(ans, score);
        }
        return dp[i][k] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j] = -1;
            }
        }        
        return solve(0, k, nums);
    }
};