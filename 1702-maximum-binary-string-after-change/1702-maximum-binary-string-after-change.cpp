class Solution {
public:
    string maximumBinaryString(string binary) {
        // 1st op reduces no of '0' and 2nd op helps in moving '0'
        int n = binary.size();
        int firstZero = INT_MAX;
        int zeroCount = 0;
        for(int i=0;i<n;i++){
            if(binary[i]=='0'){
                firstZero = min(i, firstZero);
                zeroCount++;
            }
        }
        if(zeroCount == 0 || zeroCount == 1) return binary;
        string ans(n, '1');
        ans[firstZero+zeroCount-1] = '0';
        return ans;
    }
};