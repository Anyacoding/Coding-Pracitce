法一：dp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (const string &word : wordDict) {
                int len = word.size();
                if (i >= len && s.substr(i - len, len) == word) {
                    dp[i] = dp[i - len] || dp[i]; //有可能出现这种测试"dogs"  ["dog","s","gs"]， s已经判断为真了，但判断gs则为假，只要有合理拆分dp[i]即为真
                }
            }
        }
        return dp[n];
    }
};
