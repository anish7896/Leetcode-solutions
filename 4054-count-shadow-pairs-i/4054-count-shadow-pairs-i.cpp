class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        long long ans = 0;
        for(int i=0;i<n;i++){
            while(!v.empty() && v.back()>nums[i]){
                v.pop_back();
            }
            ans += lower_bound(v.begin(), v.end(), nums[i])-v.begin();
            v.push_back(nums[i]);
        }
        return ans;
    }
};