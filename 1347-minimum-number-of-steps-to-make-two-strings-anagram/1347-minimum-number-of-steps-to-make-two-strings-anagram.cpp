class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int i=0;i<n;i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        int ans = 0;
        for(auto &[ch, cnt] : mp1){
            if(cnt>mp2[ch]){
                ans += cnt-mp2[ch];
            }
        }
        return ans;
    }
};