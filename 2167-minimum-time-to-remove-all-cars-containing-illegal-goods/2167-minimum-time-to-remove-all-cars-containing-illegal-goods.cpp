class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = (s[0]=='1' ? 1 : 0);
        for(int i=1;i<n;i++){
            if(s[i] == '0'){
                prefix[i] = prefix[i-1];
            }
            else{
                prefix[i] = min(prefix[i-1]+2, i+1);
            }
        }
        suffix[n-1] = (s[n-1]=='1' ? 1 : 0);
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0'){
                suffix[i] = suffix[i+1];
            }
            else{
                suffix[i] = min(suffix[i+1]+2, n-i);
            }
        }
        int ans = min(prefix[n-1], suffix[0]);
        for(int i=0;i<n-1;i++){
            ans = min(ans, prefix[i]+suffix[i+1]);
        }
        return ans;
    }
};