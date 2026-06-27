class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        if(mp[1]%2==0) ans = mp[1]-1;
        else ans = mp[1];
        for(auto it : mp){
            int x = it.first;
            if(x==1) continue;
            int len = 0;
            while(mp.count(x) && mp[x]>1){
                len += 2;
                x = 1LL * x*x;
            }
            if(mp.count(x) == 1) len += 1;
            else len -= 1;

            ans = max(ans, len);
        }
        return ans;
    }
};