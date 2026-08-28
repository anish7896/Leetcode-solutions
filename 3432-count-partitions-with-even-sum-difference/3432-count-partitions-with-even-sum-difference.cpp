class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftsum = 0;
        int count = 0;
        for(int i=0;i<n-1;i++){
            sum = sum-nums[i];
            leftsum += nums[i];
            if(abs(leftsum-sum)%2==0) count++;
        }
        return count;
    }
};