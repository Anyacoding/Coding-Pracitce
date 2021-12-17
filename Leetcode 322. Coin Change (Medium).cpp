法一：完全背包
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
