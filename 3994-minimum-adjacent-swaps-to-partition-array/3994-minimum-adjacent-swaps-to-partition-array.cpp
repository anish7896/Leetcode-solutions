class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int mod = 1e9+7;
        long long ans = 0;
        long long L = 0, M = 0, R = 0;
        for(auto &x : nums){
            if(x<a){
                ans += M+R;
                L++;
            }
            else if(x>=a && x<=b){
                ans += R;
                M++;
            }
            else{
                R++;
            }
        }
        return ans%mod;
    }
};