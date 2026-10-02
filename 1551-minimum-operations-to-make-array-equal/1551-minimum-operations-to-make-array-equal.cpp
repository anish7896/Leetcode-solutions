class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = (2*i)+1;
        }
        int avg = n;
        int ans = 0;
        int l=0, r=n-1;
        while(l<r){
            ans += (avg-arr[l]);
            l++;
            r--;
        }
        return ans;
    }
};