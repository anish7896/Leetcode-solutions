class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = 1LL*need1*cost1 + 1LL*need2*cost2;
        long long c2 = 1LL*max(need1, need2)*costBoth;
        long long c3 = 1LL*min(need1, need2)*costBoth + 1LL*max(0, need1-need2)*cost1 + 1LL*max(0, need2-need1)*cost2;
        return min({c1, c2, c3});
    }
};