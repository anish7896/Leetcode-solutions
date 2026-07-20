class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        int xy = 0, yx = 0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x' && s2[i]=='y') xy++;
                else yx++;
            }
        }
        if((xy+yx)%2==1) return -1;
        return xy/2 + yx/2 + (xy%2)*2;
    }
};