class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n>m) return false;
        vector<int> prefix(n, -1), suffix(n, -1);
        int j = 0;
        for(int i=0;i<n;i++){
            while(j<m && t[j]!=s[i]) j++;
            if(j==m) break;
            prefix[i] = j;
            j++;
        }
        if(prefix[n-1]!=-1) return true;
        j = m-1;
        for(int i=n-1;i>=0;i--){
            while(j>=0 && t[j]!=s[i]) j--;
            if(j<0) break;
            suffix[i] = j;
            j--;
        }
        for(int i=0;i<n;i++){
            int left = -1;
            if(i>0){
                if(prefix[i-1]==-1) continue;
                left = prefix[i-1];
            }
            int right = m;
            if(i+1<n){
                if(suffix[i+1]==-1) continue;
                right = suffix[i+1];
            }
            if(right-left>1) return true;
        }
        return false;
    }
};