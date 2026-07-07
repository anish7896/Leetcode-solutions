class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n =  nums.size();
        int l=0, r=0, maxlen = INT_MIN;
        deque<int> maxdq, mindq;
        while(r<n){
            while(!maxdq.empty() && nums[maxdq.back()]<nums[r]){
                maxdq.pop_back();
            }
            while(!mindq.empty() && nums[mindq.back()]>nums[r]){
                mindq.pop_back();
            }
            maxdq.push_back(r);
            mindq.push_back(r);
            while(nums[maxdq.front()]-nums[mindq.front()] > limit){
                if(maxdq.front()==l) maxdq.pop_front();
                if(mindq.front()==l) mindq.pop_front();
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};