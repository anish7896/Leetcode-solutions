class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        string s1 = "", s2 = "";
        for(char ch : start){
            if(ch!='_') s1 += ch;
        }
        for(char ch : target){
            if(ch!='_') s2 += ch;
        }
        if(s1 != s2) return false;
        vector<int> startPosL, startPosR;
        for(int i=0;i<n;i++){
            if(start[i]=='L'){
                startPosL.push_back(i);
            }
            else if(start[i]=='R'){
                startPosR.push_back(i);
            }
        }
        int l = 0, r = 0;
        for(int i=0;i<n;i++){
            if(target[i]=='L'){
                if(i>startPosL[l]){
                    return false;
                }
                l++;
            }
            else if(target[i]=='R'){
                if(i<startPosR[r]){
                    return false;
                }
                r++;
            }
        }
        return true;
    }
};