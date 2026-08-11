class Solution {
public:
    void merge(vector<int> &nums, int l, int m, int r){
        vector<int> temp;
        int i = l, j = m+1;
        int cnt = 0;
        while(i<=m && j<=r){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=m){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=l;k<=r;k++){
            nums[k] = temp[k-l];
        }
    }
    long long countPairs(vector<int> &nums, int l, int m, int r){
        int j = m+1;
        long long cnt = 0;
        for(int i=l;i<=m;i++){
            while(j<=r && (long long)nums[i]>2LL*nums[j]) j++;
            cnt += (j-(m+1));
        }
        return cnt;
    }
    long long mergeSort(vector<int> &nums, int l, int r){
        long long cnt = 0;
        if(l>=r) return 0;
        int m = l + (r-l)/2;
        cnt += mergeSort(nums, l, m);
        cnt += mergeSort(nums, m+1, r);
        cnt += countPairs(nums, l, m, r);
        merge(nums,l,m,r);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};