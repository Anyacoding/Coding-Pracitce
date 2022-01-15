法一:dp,股票问题的通用解法
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //对于每一天i，都有两种状态
        //dp[i][0],代表不持股
        //dp[i][1],代表持股
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0; //第0天不持股说明没有买入捏
        dp[0][1] = -(fee + prices[0]); //第0天持股说明买入了并交手续费
        for (int i = 1; i < n; ++i) {
            //第i天不持股有两种情况，一种是前一天也不持股，另一种是前天持股今天卖掉
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            //第i天持股有两种情况，一种是前一天也持股，另一种是前天不持股今天买入
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - fee - prices[i]);
        }
        return dp[n - 1][0];
    }
};
