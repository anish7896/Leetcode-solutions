
class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();

        long long ans = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {

            // Check whether "abc" ends at j
            if (j >= 2 &&
                s[j-2] == 'a' &&
                s[j-1] == 'b' &&
                s[j] == 'c') {

                i = j - 1;
            }

            // Count valid substrings ending at j
            ans += (j - i + 1);
        }

        return ans;
    }
};
