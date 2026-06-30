class Solution {
public:
    int countPairs(vector<int>& nums, int x){
        int n = nums.size();
        int count = 0;
        int left = 0;
        for(int right=1;right<n;right++){
            while(nums[right]-nums[left]>x) left++;
            count += right-left;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = abs(nums[n-1]-nums[0]);
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(countPairs(nums, mid) >= k){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};