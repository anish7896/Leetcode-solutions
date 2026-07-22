class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isFlipped(n, false);
        int flips = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i>=3 && isFlipped[i-3]){
                flips--;
            }
            if(flips%2 == nums[i]){
                if(i+3>n) return -1;
                flips++;
                ans++;
                isFlipped[i] = true;
            }
        }
        return ans;
    }
};