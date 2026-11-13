class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.length();
        vector<vector<string>> ans;
        int start = -1;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(start==-1){
                    start = i;
                }
            }
            else{
                if(start!=-1){
                    string sub1 = s1.substr(start, i-start);
                    string sub2 = s2.substr(start, i-start);
                    ans.push_back({sub1, sub2});
                    start = -1;
                }
            }
        }
        if(start!=-1){
            string sub1 = s1.substr(start);
            string sub2 = s2.substr(start);
            ans.push_back({sub1, sub2});
        }
        return ans;
    }
};