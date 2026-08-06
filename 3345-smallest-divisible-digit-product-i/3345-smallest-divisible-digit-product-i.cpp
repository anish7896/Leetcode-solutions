class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = INT_MAX;
        for(int i=n;i<=100;i++){
            int num = i;
            int prod = 1;
            while(num>0){
                int lastdigit = num%10;
                prod *= lastdigit;
                num /= 10;
            }
            num = i;
            if(prod%t==0){
                ans = min(ans, num);
            } 
        }
        return ans;
    }
};