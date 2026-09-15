class Solution {
public:
    bool solve(int i, int j, string& s){
        if(i>=j) return true;
        if(s[i]==s[j]) return solve(i+1, j-1, s);
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int len = INT_MIN;
        int start = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i, j, s)==true){
                    if(j-i+1>len){
                        len = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};