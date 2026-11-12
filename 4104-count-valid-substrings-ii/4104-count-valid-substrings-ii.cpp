class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.length();
        int lasta = -1;
        int lastab = -1;
        int lastabc = -1;
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                lasta = i;
            }
            else if(s[i]=='b'){
                if(lasta!=-1){
                    lastab = max(lastab, lasta);
                }
            }
            else if(s[i]=='c'){
                if(lastab!=-1){
                    lastabc = max(lastabc, lastab);
                }
            }
            ans += i-lastabc;
        }
        return ans;
    }
};