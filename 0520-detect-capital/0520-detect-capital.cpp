class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z') cnt1++;
            else if(word[i]>='a' && word[i]<='z') cnt2++;
        }
        return (cnt1==n || cnt2==n || ((word[0]>='A' && word[0]<='Z') && (cnt2 == n-1)));
    }
};