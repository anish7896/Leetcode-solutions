class Solution {
public:
    int count(int m, int n, int mid){
        int cnt = 0;
        for(int i=1;i<=m;i++){
            cnt += min(mid/i, n);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int lo = 1;
        int hi = m*n;
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(count(m,n,mid) >= k){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};