class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        s1 = ' ' + s1; //空白哨兵小技巧，避免了i - 1越界的情况
        s2 = ' ' + s2;
        //定义dp[i][j]表示字符串s1的[1,i]区间和字符串s2的[1,j]区间的最长公共子序列长度（下标从1开始）。
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0)); //对dp初始化
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else if (s1[i] != s2[j]) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
