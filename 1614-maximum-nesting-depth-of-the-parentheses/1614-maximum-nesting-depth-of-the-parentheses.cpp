class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char> st;
        int ans = 0;
        int depth = 0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch=='('){
                st.push(s[i]);
                depth++;
                ans = max(ans, depth);
            }
            if(s[i]==')' && !st.empty()){
                st.pop();
                depth--;
            }
        }
        return ans;
    }
};