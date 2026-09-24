class Solution {
public:
    struct Job{
        int start;
        int end;
        int profit;
    };
    int findPrev(vector<Job>& jobs, int i){
        int lo = 0;
        int hi = i-1;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(jobs[mid].end<=jobs[i].start){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        for(int i=0;i<startTime.size();i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b){
            return a.end < b.end;
        });
        int n = jobs.size();
        vector<int> dp(n, 0);
        for(int i=0;i<n;i++){
            int skip = (i==0 ? 0 : dp[i-1]);
            int prev = findPrev(jobs, i);
            int take = jobs[i].profit;
            if(prev != -1) take += dp[prev];
            dp[i] = max(skip, take);
        }
        return dp[n-1];
    }
};