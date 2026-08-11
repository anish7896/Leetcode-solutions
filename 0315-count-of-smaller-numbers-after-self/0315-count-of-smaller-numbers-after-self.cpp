class Solution {
public:
    void merge(vector<pair<int, int>> &arr, int l, int m, int r, vector<int>& ans){
        vector<pair<int, int>> temp;
        int i = l, j = m+1;
        int rightsmaller = 0;
        while(i<=m && j<=r){
            if(arr[i].first<=arr[j].first){
                ans[arr[i].second] += rightsmaller;
                temp.push_back(arr[i]);
                i++;
            }
            else{
                rightsmaller++;
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=m){
            ans[arr[i].second] += rightsmaller;
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(arr[j]);
            j++;
        }
        for(int k=l;k<=r;k++){
            arr[k] = temp[k-l];
        }
    }
    void mergeSort(vector<pair<int, int>> &arr, int l, int r, vector<int>& ans){
        if(l>=r) return;
        int m = l+(r-l)/2;
        mergeSort(arr, l, m, ans);
        mergeSort(arr, m+1, r, ans);
        merge(arr, l, m, r, ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i], i});
        }
        vector<int> ans(n, 0);
        mergeSort(arr, 0, n-1, ans);
        return ans;
    }
};