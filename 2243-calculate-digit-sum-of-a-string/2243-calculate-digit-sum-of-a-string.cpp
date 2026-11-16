class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string group = "";
            vector<string> v;
            for(int i=0;i<s.length();i++){
                group += s[i];
                if(group.size()==k){
                    v.push_back(group);
                    group = "";
                }
            }
            if(group!=""){
                v.push_back(group);
            }
            string temp = "";
           
            for(int i=0;i<v.size();i++){
                string a = v[i];
                int sum = 0;
                for(int j=0;j<a.size();j++){
                    sum += a[j]-'0';
                }
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;   
    }
};