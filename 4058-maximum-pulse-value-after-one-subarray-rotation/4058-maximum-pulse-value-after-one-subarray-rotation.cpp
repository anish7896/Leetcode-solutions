class Solution {
public:
    long long solve(vector<long long>& b){
        int n = b.size();
        if(n<2) return 0;
        vector<long long> dp(n, 0);
        dp[n-1] = 0;
        dp[n-2] = b[n-2]+b[n-1];
        for(int i=n-3;i>=0;i--){
            dp[i] = b[i]+b[i+1];
            if(dp[i+2]>0) dp[i] += dp[i+2];
        }
        return *max_element(dp.begin(), dp.end());
    }
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        long long pulse = 0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                pulse += nums[i];
            }
            else{
                pulse -= nums[i];
            }
        }
        vector<long long> b(n, 0);
        for(int i=0;i<n;i++){
            if(i%2==0){
                b[i] = -2LL*nums[i];
            }
            else{
                b[i] = 2LL*nums[i];
            }
        }
        long long maxsum = solve(b);
        return pulse+maxsum;
    }
};