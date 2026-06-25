class Solution {
public:
    int appendCharacters(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        int i = 0, j = 0;
        while(n1>i && n2>j){
            if(s[i]==t[j]){
                i++, j++;
            }
            else{
                i++;
            }
        }
        return n2-j;
    }
};