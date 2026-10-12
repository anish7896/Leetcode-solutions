class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<=n;i++){
            if(isPrime[i]==true && i<=s){
                ans.push_back(i);
                s -= i;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};