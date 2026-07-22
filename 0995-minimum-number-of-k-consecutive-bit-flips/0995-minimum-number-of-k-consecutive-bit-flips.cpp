class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> isFlipped(n, false);
        int activeFlips = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            // Remove the effect of the flip that expired
            if(i>=k && isFlipped[i-k]){
                activeFlips--;
            }
            // Current bit becomes 0 if:
            // (activeFlips is even and nums[i] == 0)
            // OR
            // (activeFlips is odd and nums[i] == 1)
            if(activeFlips%2 == nums[i]){
                if(i+k>n) return -1;
                activeFlips++;
                ans++;
                isFlipped[i] = true;
            }
        }
        return ans;
    }
};