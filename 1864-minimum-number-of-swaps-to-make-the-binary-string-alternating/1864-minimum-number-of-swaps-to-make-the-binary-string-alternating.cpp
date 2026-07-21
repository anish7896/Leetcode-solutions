class Solution {
public:
    int minSwaps(string s) {
       int n = s.size();
       int cnt_0 = 0, cnt_1 = 0;
       for(int i=0;i<n;i++){
        if(s[i]=='0') cnt_0++;
        else cnt_1++;
       } 
       if(abs(cnt_0-cnt_1)>1) return -1;
       int mismatch0 = 0; //01010101...
       int mismatch1 = 0; //1010101...
       for(int i=0;i<n;i++){
        char expected0 = (i%2==0) ? '0' : '1';  //even me 0 odd me 1 like 010101..
        char expected1 = (i%2==0) ? '1' : '0';  // odd me 1 even me 0 like 101010...
        if(s[i]!=expected0) mismatch0++;
        if(s[i]!=expected1) mismatch1++;
       }
       if(cnt_0>cnt_1) return mismatch0/2;
       if(cnt_1>cnt_0) return mismatch1/2;
       return min(mismatch0, mismatch1)/2;
    }
};