class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        stack<int> st;
        int ans = 0;
        for(int i=0;i<n;i++){
            int defense = properties[i][1];
            while(!st.empty() && st.top()<defense){
                ans++;
                st.pop();
            }
            st.push(defense);
        }
        return ans;
    }
};