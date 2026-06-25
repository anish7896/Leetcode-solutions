class Solution {
public:
    bool check(vector<int>& nums, int maxOperations, int x){
        long long operation = 0;
        for(int i=0;i<nums.size();i++){
            operation += (nums[i]-1)/x;
        }
        return operation<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(nums, maxOperations, mid)){
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