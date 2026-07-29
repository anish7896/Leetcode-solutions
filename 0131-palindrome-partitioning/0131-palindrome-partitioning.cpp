class Solution {
public:
    vector<vector<string>> output;
    vector<string> ans;
    bool isPalindrome(int i, int j, string& s){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int i, string& s){
        int n = s.size();
        if(i==n){
            output.push_back(ans);
            return;
        };
        for(int j=i;j<n;j++){
            if(isPalindrome(i, j, s)){
                ans.push_back(s.substr(i, j-i+1));
                solve(j+1, s);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(0, s);
        return output;
    }
};