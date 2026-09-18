class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> start(26, -1);
        vector<int> end(26, -1);
        for(int i=0;i<n;i++){
            int idx = s[i]-'a';
            if(start[idx] == -1){
                start[idx] = i;
            }
            end[idx] = i;
        }
        vector<pair<int, int>> interval;
        for(int i=0;i<26;i++){
            if(start[i]==-1) continue;
            int l = start[i];
            int r = end[i];
            bool flag = true;
            for(int i=l;i<=r;i++){
                int idx = s[i]-'a';
                if(start[idx]<l){
                    flag = false;
                    break;
                }
                r = max(r, end[idx]);
            }
            if(flag==true){
                interval.push_back({r,l});
            }
        }
        sort(interval.begin(), interval.end());
        vector<string> ans;
        int prev = -1;
        for(auto &[r,l] : interval){
            if(l>prev){
                ans.push_back(s.substr(l, r-l+1));
                prev = r;
            }
        }
        return ans;
    }
};