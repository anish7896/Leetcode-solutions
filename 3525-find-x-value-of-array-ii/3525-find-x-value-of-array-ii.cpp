class Solution {

    struct Node {
        int cnt[5] = {0};
        int prod = 0;
    };
    class SegmentTree {
        int n, k;
        vector<Node> segTree;
    public:
        SegmentTree(vector<int>& nums, int k) {
            this->k = k;
            n = nums.size();
            segTree.resize(4 * n);
            build(0, 0, n - 1, nums);
        }
        void leafNode(int i, int value) {
            int rem = value % k;
            segTree[i].cnt[rem] = 1;
            segTree[i].prod = rem;
        }
        Node mergeNodes(Node& left, Node& right) {
            Node result;
            result.prod = (left.prod * right.prod) % k;
            for (int x = 0; x < k; x++) {
                result.cnt[x] = left.cnt[x];
            }
            for (int x = 0; x < k; x++) {
                int newRem = (left.prod * x) % k;
                result.cnt[newRem] += right.cnt[x];
            }
            return result;
        }
        void build(int i, int l, int r, vector<int>& nums) {
            if (l == r) {
                leafNode(i, nums[l]);
                return;
            }
            int mid = l + (r - l) / 2;
            build(2 * i + 1, l, mid, nums);
            build(2 * i + 2, mid + 1, r, nums);
            segTree[i] =
                mergeNodes(segTree[2 * i + 1], segTree[2 * i + 2]);
        }
        void updateTree(int i, int l, int r, int index, int value) {
            if (l == r) {
                segTree[i] = Node();
                leafNode(i, value);
                return;
            }
            int mid = l + (r - l) / 2;
            if (index <= mid) {
                updateTree(2 * i + 1, l, mid, index, value);
            } else {
                updateTree(2 * i + 2, mid + 1, r, index, value);
            }
            segTree[i] =
                mergeNodes(segTree[2 * i + 1], segTree[2 * i + 2]);
        }
        void update(int index, int value) {
            updateTree(0, 0, n - 1, index, value);
        }
        Node queryTree(int i, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) {
                return segTree[i];
            }
            int mid = l + (r - l) / 2;
            if (qr <= mid) {
                return queryTree(2 * i + 1, l, mid, ql, qr);
            }
            if (ql > mid) {
                return queryTree(
                    2 * i + 2, mid + 1, r, ql, qr);
            }
            Node left = queryTree(2 * i + 1, l, mid, ql, qr);
            Node right = queryTree(2 * i + 2, mid + 1, r, ql, qr);
            return mergeNodes(left, right);
        }
        Node query(int l, int r) {
            return queryTree(0, 0, n - 1, l, r);
        }
    };
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree st(nums, k);
        vector<int> ans;

        for(auto& q : queries){

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;
            st.update(index, value);

            Node res = st.query(start, nums.size() - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};