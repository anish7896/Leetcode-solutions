class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int cumsum = 0;
        mp[0] = 1;
        long long points = 0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                points += mp[cumsum];
                cumsum += 1;
            }
            else{
                cumsum -= 1;
                points -= mp[cumsum];
            }
            mp[cumsum] += 1;
            ans += points;
        }
        return ans;
    }
};