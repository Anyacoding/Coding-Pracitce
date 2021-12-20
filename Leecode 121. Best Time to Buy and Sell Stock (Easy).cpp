class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 999999;
        int sell = 0;
        for (int i = 0; i < prices.size(); ++i) {
            buy = min(buy, prices[i]); //选出[0,i]之间最小的股价
            sell = max(sell, prices[i] - buy); //比较之前的sell和当前抛出股票哪种更赚
        }
        return sell;
    }
};
