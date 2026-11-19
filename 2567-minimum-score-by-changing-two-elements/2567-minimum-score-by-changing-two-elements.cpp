class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int s1 = abs(nums[n-2]-nums[1]);
        int s2 = abs(nums[n-3]-nums[0]);
        int s3 = abs(nums[n-1]-nums[2]);
        return min({s1,s2,s3});
    }
};