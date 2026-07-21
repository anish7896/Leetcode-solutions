class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int ans = 0;
        char current = '0';
        for(int i=0;i<n;i++){
            if(target[i]!=current){
                ans++;
                current = (current=='0') ? '1' : '0';
            }
        }
        return ans;
    }
};