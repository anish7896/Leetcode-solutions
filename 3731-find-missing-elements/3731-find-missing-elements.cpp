class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(mpp.find(i)==mpp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};