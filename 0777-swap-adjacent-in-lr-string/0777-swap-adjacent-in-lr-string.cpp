class Solution {
public:
    bool canTransform(string start, string result) {
        // Think X as empty space same like previous problem 2337
        int n = start.size();
        string s1 = "", s2 = "";
        for(int i=0;i<n;i++){
            if(start[i]!='X') s1 += start[i];
        }
        for(int i=0;i<n;i++){
            if(result[i]!='X') s2 += result[i];
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
            if(result[i]=='L'){
                if(i>startPosL[l]) return false;
                l++;
            }
            else if(result[i]=='R'){
                if(i<startPosR[r]) return false;
                r++;
            }
        }
        return true;

    }
};