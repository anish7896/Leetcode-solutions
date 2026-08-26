class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        string ans = "";
        for(int right=0;right<n;right++){
            if(s[right]=='1'){
                ones++;
            }
            while(ones>k){
                if(s[left] == '1'){
                    ones--;
                }
                left++;
            }
            while(ones==k && s[left]=='0' && left<right){
                left++;
            }
            if(ones==k){
                string temp = s.substr(left, right-left+1);
                if(ans=="" || temp.size()<ans.size() || (temp.size()==ans.size() && temp<ans)){
                    ans = temp;
                }
            }
        }
        return ans;
    }
};