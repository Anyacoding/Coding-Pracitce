法一：完全背包，压缩写法，直接内层正序遍历容量
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //dp[i][j]表示前i个硬币尽量装满容量为j的背包的最少硬币数
        vector<int> dp(amount + 1, 99999);
        //dp[0][0] = 0 表示为前0个元素能装满容量为0的背包最少数就是0
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] != 99999) {
            return dp[amount];
        }
        else {
            return -1;
        }
        
    }
};

法二：完全背包，不压缩写法
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //dp[i][j]表示前i个硬币尽量装满容量为j的背包的最少硬币数
        vector<vector<int>> dp(n + 1, vector(amount + 1, 99999));
        //dp[0][0] = 0 表示为前0个元素能装满容量为0的背包最少数就是0
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j >= coins[i - 1]) {
                    //完全背包问题，同一个物品能多次放入
                    //如果能装的下当前物品，则状态转移自dp[i][j - coins[i - 1]]，即之前已经放过当前物体，这里继续尝试放入
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][amount] != 99999) {
            return dp[n][amount];
        }
        else {
            return -1;
        }
        
    }
};
