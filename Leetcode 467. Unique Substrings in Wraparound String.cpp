法一：线性dp来统计字符串的子串
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int ans = 0;
        int n = p.size();
        int k = 0;
        vector<int> dp(26, 0);
        for (int i = 0; i < n; ++i) {
            if (i > 0 && (p[i] - p[i - 1] + 26) % 26 == 1) {
                ++k;
            }
            else k = 1;
            dp[p[i] - 'a'] = max(k, dp[p[i] - 'a']);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
