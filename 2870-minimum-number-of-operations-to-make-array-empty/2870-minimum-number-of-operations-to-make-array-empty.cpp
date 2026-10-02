class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int ans = 0;
        for(auto &it : freq){
            int f = it.second;
            if(f==1) return -1;
            if(f%3==0){
                ans += f/3;
            }
            else{
                ans += (f+2)/3;
            }
        }
        return ans;
    }
};