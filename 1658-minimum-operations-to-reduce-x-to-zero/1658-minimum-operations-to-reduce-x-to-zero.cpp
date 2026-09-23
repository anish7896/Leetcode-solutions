class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int target = total_sum-x;
        if(target<0) return -1;
        int l = 0, r = 0;
        int maxlen = -1;
        int sum = 0;
        while(r<n){
            sum += nums[r];
            while(sum>target){
                sum -= nums[l];
                l++;
            }
            if(sum==target){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        if(maxlen == -1) return -1;
        return n-maxlen;
    }
};