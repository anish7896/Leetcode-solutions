class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int l = 0, r = 0;
        long long ans = 0;
        while(r<n){
            if(nums[r]<minK || nums[r]>maxK){
                l = r+1;
            }
            else{
                ans += r-l+1;
            }
            r++;
        }
        return ans;
    }
};