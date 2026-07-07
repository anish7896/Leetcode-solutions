class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                ans += s[i];
            }
        }
        if(ans.empty())
            return 0;
        long long x = stoll(ans);
        long long sum = 0;
        long long temp = x;
        while(x>0){
            int last_digit = x%10;
            sum += last_digit;
            x /= 10;
            
        }
        return sum*temp;
        
    }
};