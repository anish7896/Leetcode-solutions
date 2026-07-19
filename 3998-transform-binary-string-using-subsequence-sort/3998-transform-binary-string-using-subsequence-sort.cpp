class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        
        // count total zeros in original string
        int totalZeros = 0;
        vector<int> zeroPos;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                totalZeros++;
                zeroPos.push_back(i);
            }
        }
        vector<bool> ans;
        for(string t : strs){
            int currentZeros = 0;
            int questionMarks = 0;
            for(char ch : t){
                if(ch=='0') currentZeros++;
                else if(ch=='?') questionMarks++;
            }

            // Impossible to make required number of zeros
            if(currentZeros > totalZeros || currentZeros+questionMarks < totalZeros){
                ans.push_back(false);
                continue;
            }
        
            int needZeros = totalZeros - currentZeros;

            // Fill '?' greedily
            for(int i=0;i<n;i++){
                if(t[i]=='?'){
                    if(needZeros>0){
                        t[i] = '0';
                        needZeros--;
                    }
                    else{
                        t[i] = '1';
                    }
                }
            }
            vector<int> targetZeroPos;
            for(int i=0;i<n;i++){
                if(t[i]=='0'){
                    targetZeroPos.push_back(i);
                }
            }
            bool possible = true;
            for(int i=0;i<totalZeros;i++){
                if(zeroPos[i]<targetZeroPos[i]){
                    possible = false;
                    break;
                }
            }
            ans.push_back(possible);
        }
        return ans;
    }
};