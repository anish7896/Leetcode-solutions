class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();
        if(n2>n1) return -1;
        int i=0, j=0;
        int ans = -1;
        while(i<n1){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==n2) return i-n2;
            }
            else{
                i = i-j+1;
                j=0;
            }
        }
        return -1;
    }
};