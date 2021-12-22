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
