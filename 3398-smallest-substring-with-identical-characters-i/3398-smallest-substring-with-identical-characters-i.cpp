class Solution {
public:
    bool check(int mid, string s, int numOps){
        if(mid==1){
            int flips0 = 0;
            int flips1 = 0;
            for(int i=0;i<s.length();i++){
                // Pattern 010101...
                if(s[i] != (i%2==0 ? '0' : '1')) flips0++;
                // Pattern 101010...
                if(s[i] != (i%2==0 ? '1' : '0')) flips1++;
            }
            return min(flips0, flips1)<=numOps;
        }
        int cnt = 1;
        int flips = 0;
        for(int i=1;i<=s.length();i++){
            if(i<s.length() && s[i]==s[i-1]){
                cnt++;
            }
            else{
                flips += cnt/(mid+1);
                cnt = 1;
            }
        }
        return flips<=numOps;
    }
    int minLength(string s, int numOps) {
        int n = s.size();
        int lo = 1;
        int hi = n;
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid, s, numOps)){
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