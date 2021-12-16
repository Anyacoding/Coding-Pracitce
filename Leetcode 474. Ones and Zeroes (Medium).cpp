法一：01背包变形
class Solution {
public:
    pair<int, int> count(const string& str) {
        int count0 = 0;
        int count1 = 0;
        for (const char it : str) {
            if (it == '0') {
                ++count0;
            }
            else {
                ++count1;
            }
        }
        return pair<int, int>(count0, count1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        //dp[i][j][k] 表示输入字符串在子区间 [0, i] 能够使用 j 个 0 和 k 个 1 的字符串的最大数量。
        int dp[len + 1][m + 1][n + 1];
        //i = 0时可以认为字符串为空，所以字符串的最大数量为0，所以先初始化为0
        int count0, count1;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len; ++i) {
            auto[count0, count1] = count(strs[i - 1]);
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    //可以装的下
                    if (j >= count0 && k >= count1) {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i -1][j - count0][k - count1] + 1);
                    }
                    //装不下，则直接从i-1转移状态
                    else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp[len][m][n];
    }
};

法二：滚动数组路径压缩
class Solution {
public:
    pair<int, int> count(const string& str) {
        int count0 = 0;
        int count1 = 0;
        for (const char it : str) {
            if (it == '0') {
                ++count0;
            }
            else {
                ++count1;
            }
        }
        return pair<int, int>(count0, count1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        //dp[i][j][k] 表示输入字符串在子区间 [0, i] 能够使用 j 个 0 和 k 个 1 的字符串的最大数量。
        //这里使用滚动数组降低一个维度
        int dp[m + 1][n + 1];
        int count0, count1;
        //滚动数组可以全部初始化为0
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len; ++i) {
            auto[count0, count1] = count(strs[i - 1]);
            for (int j = m; j >= count0; --j) {
                for (int k = n; k >= count1; --k) {
                        dp[j][k] = max(dp[j][k], dp[j - count0][k - count1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
