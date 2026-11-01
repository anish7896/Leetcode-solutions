class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        vector<int> diff(n+1, 0);
        int inversion = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    inversion++;
                    diff[i]++;
                    diff[j+1]--;
                }
            }
        }
        int x = 0;
        int y = 0;
        for(int i=0;i<n;i++){
            x += diff[i];
            if(x>0 && locked[i]==1) y++;
        }
        if(y>k) return -1;
        return inversion+y;
    }
};