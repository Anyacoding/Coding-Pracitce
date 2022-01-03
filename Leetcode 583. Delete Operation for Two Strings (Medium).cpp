法一：lcs变种，注意初始化就还ok
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        word1 = ' ' + word1;
        word2 = ' ' + word2;
        //dp[i][j]表示word1前i个字符和word2前j个字符相同所需要的最小步数
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        //进行初始化，dp[i][0]要使两个字符串相等，则要执行i次删除操作，dp[0][j]同理
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                //当前最后一位字母相同，则不需要操作，状态转移自dp[i-1][j-1]
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
