class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n; //因为第1阶只有一种方法，第2阶只有两种方法
        vector<int> dp(n + 1, 1); //状态数组
        for (int i = 2; i <= n; ++i) {
            //这就是状态转移方程
            dp[i] = dp[i - 1] + dp[i - 2]; //第i阶台阶可以由第i-1阶和第i-2阶走到，换句话说第i阶的走法等于第i-1加上第i-2阶的走法
        }
        return dp[n];
    }
};
