class Solution {
public:
    int digitsum(int x){
        int sum = 0;
        while(x>0){
            int last_digit = x%10;
            sum += last_digit;
            x /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(digitsum(x)==i){
                return i;
            }
        }
        return -1;
    }
};