class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            int index = s[i]-'a';
            int reverse_value = 26-index;
            sum += (reverse_value*(i+1));
        }
        return sum;
    }
};