class Solution {
public:
    int countSubarray(vector<int>& nums, int largestSum){
        int parts = 1;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=largestSum){
                sum += nums[i];
            }
            else{
                parts++;
                sum = nums[i];
            }
        }
        return parts;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        long long lo = *max_element(nums.begin(), nums.end());
        long long hi = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = 0;
        while(lo<=hi){
            long long mid = lo+(hi-lo)/2;
            if(countSubarray(nums, mid)<=k){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return (int)ans;
    }
};