法一：动态规划
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        word1 = ' ' + word1; //大无语事件，bug就出在这里' ' + word1 和 word1 + ' ' 完全不同捏呜呜
        word2 = ' ' + word2;
        //dp[i][j]表示word1的[0,i]区间和字符串word2的[0,j]区间转换的最少操作数
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        //因为dp[0][0]word1和word2都是空格，不需要操作转换所以为0
        //因为i=0时，dp[0][j] = j; 例如“” “ros” 就最少需要三次操作. j=0时同理
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                //当前最后一位字符相等，说明不用操作，状态转移自i-1和j-1即可
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                //不相等时有三种备选操作
                else {
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};
