class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if(st.find(endGene) == st.end()) return -1;
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        st.erase(startGene);
        vector<char> gene = {'A','C','G','T'};
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endGene) return steps;
            for(int i=0;i<8;i++){
                char original = word[i];
                for(char &ch : gene){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return -1;
    }
};