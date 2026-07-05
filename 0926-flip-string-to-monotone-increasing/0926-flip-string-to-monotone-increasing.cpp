class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n+1, 0), suffix(n+1, 0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + (s[i] == '1');
        }
        for(int i=n-1;i>=0;i--){
            suffix[i] = suffix[i+1] + (s[i] == '0');
        }
        int ans = n;
        for(int i=0;i<=n;i++){
            ans = min(ans, suffix[i]+prefix[i]);
        }
        return ans;
    }
};