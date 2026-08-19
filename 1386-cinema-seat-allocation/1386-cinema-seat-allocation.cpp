class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for(auto &x : reservedSeats){
            int row = x[0];
            int seat = x[1];
            mp[row] |= (1 << seat);
        }
        int left   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        int ans = 2*n;

        for(auto &[row, mask] : mp){

            bool L = (mask & left) != 0;
            bool M = (mask & middle) != 0;
            bool R = (mask & right) != 0;

            if(!L && !R){
                continue;
            }

            if(!L||!M||!R){
                ans--;
            }

            else{
                ans -= 2;
            }
        }

        return ans;
    }
};