class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            bool increasing = true;
            bool decreasing = true;
            for(int j=i;j<n;j++){
                if(j>i){
                    if(nums[j]>=nums[j-1]){
                        decreasing = false;
                    }
                    if(nums[j-1]>=nums[j]){
                        increasing = false;
                    }
                }
                if(increasing || decreasing) ans = max(ans, j-i+1);
                else break;
            }
        }
        return ans;
    }
};