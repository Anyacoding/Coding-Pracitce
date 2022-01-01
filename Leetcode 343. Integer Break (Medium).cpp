class Solution {
public:
    // 动态规划， 拆分整数得到拆分数的最大乘积
	// # 假设对正整数 i 拆分出的第一个正整数是 j（1 <= j < i），则有以下两种方案：
	// # 1) 将 i 拆分成 j 和 i−j 的和，且 i−j 不再拆分成多个正整数，此时的乘积是 j * (i-j)
	// # 2) 将 i 拆分成 j 和 i−j 的和，且 i−j 继续拆分成多个正整数，此时的乘积是 j * dp[i-j]
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            int cur = 0;
            for (int j = 1; j < i; ++j) {
                cur = max(cur, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = cur;
        }
        return dp[n];
    }
};
