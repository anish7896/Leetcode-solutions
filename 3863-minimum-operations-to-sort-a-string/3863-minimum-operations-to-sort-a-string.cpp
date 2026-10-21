class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string temp = s;
        sort(temp.begin(), temp.end());
        if(temp==s) return 0;
        if(n==2) return -1;
        char mx = *max_element(s.begin(), s.end());
        char mn = *min_element(s.begin(), s.end());
        if(s[0]==mn || s[n-1]==mx) return 1;
        int maxcount = count(s.begin(), s.end(), mx);
        int mincount = count(s.begin(), s.end(), mn);
        if(s[0]==mx && s[n-1]==mn && maxcount==1 && mincount==1) return 3;
        return 2;
    }
};