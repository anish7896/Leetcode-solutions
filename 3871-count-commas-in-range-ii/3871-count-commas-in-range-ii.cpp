class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long ans = 0;
        long long lower = 1000;
        long long comma = 1;
        while(lower<=n){
            long long upper = lower*1000-1;
            if(upper>n) upper = n;
            long long count = upper-lower+1; 
            ans += count*comma;
            lower *= 1000;
            comma++;
        }
        return ans;
    }
};