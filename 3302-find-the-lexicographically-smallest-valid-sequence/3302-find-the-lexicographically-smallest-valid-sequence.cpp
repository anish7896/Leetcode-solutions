class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> suff(n+1, 0);
        int i = n-1, j = m-1;
        int matched = 0;
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                matched++;
                j--;
            }
            suff[i] = matched;
            i--;
        }
        while(i>=0){
            suff[i] = matched;
            i--;
        }
        vector<int> seq;
        bool usedMismatch = false;
        i = 0, j = 0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }
            else if(usedMismatch==false && suff[i+1]>=m-j-1){
                seq.push_back(i);
                usedMismatch = true;
                j++;
            }
            i++;
        }
        if(j==m) return seq;
        return {};

    }
};