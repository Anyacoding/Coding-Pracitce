法一：dp不压缩
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        //如果k大于等于天数，那么就可以买了抛，抛了买
        if (days <= k) {
            int ans = 0;
            for (int i = 1; i < days; ++i) {
                if (prices[i] > prices[i - 1]) {
                    ans += prices[i] - prices[i - 1];
                }
            }
            return ans;
        }
        //如果k小于天数
        //dp[i][k][0]表示第i天进行第k笔交易，且目前手上没有持有股票时能赚到最大的金额
        //dp[i][k][1]表示第i天进行第k笔交易，且目前手上持有股票时能赚到最大的金额
        //每笔交易有三种操作，买，抛，摆
        int dp[days][k + 1][2];
        //进行初始化
        memset(dp, 0, sizeof(dp));
        //第一天的时候买入的情况初始化
        for (int j = 0; j <= k; ++j) {
            dp[0][j][1] = -prices[0];
        }
        for (int i = 1; i < days; ++i) {
            for (int j = 1; j <= k; ++j) {
                //如果不做操作，则直接状态转移自dp[i - 1][j][1];如果要达到dp[i][j][1]，则在今天买入即dp[i - 1][j - 1][0] - prices[i]
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                //如果不做操作，则直接状态转移自dp[i - 1][j][0];如果要达到dp[i][j][1]，则在今天抛出即dp[i - 1][j][0] + prices[i]
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
            }
        }
        return dp[days - 1][k][0];
    }
};

法二：dp压缩
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        //如果k大于等于天数，那么就可以买了抛，抛了买
        if (days <= k) {
            int ans = 0;
            for (int i = 1; i < days; ++i) {
                if (prices[i] > prices[i - 1]) {
                    ans += prices[i] - prices[i - 1];
                }
            }
            return ans;
        }
        //如果k小于天数
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int i = 0; i < days; ++i) {
            for (int j = 1; j <= k; ++j) {
                //时刻注意自己手中的钱，让自己手中的钱始终是当前情况下最多的，这一次是买还是卖只与上一次是买还是卖有关
                buy[j] = max(buy[j], sell[j-1] - prices[i]); //buy对应着减少钱，但是要钱最多的那种情况
                sell[j] = max(sell[j], buy[j] + prices[i]); //sell对应着增加钱，但是要钱最多的那种情况
            }
        }
        return sell[k];
    }
};
