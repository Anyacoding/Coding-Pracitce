法一：dp法
class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        s = ' ' + s; //加一个空格作为哨兵，防止 i-1 出现越界情况
        vector<int> dp(size + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= size; ++i) {
            int cur = s[i] - '0'; // cur : 代表「当前位置」单独形成 item     
            int pre = (s[i - 1] - '0') * 10 + cur; // pre : 代表「当前位置」与「前一位置」共同形成 item
            //cur 是有效数字,那么 dp[i] 可以由 dp[i - 1] 转移过来
            if (cur >= 1 && cur <= 9) {
                dp[i] += dp[i - 1]; //由于dp[i] = 0, 所以等价于dp[i] += dp[i - 1]
            }
            // 如果 pre 属于有效值，那么 dp[i] 可以由 dp[i - 2] 或者 dp[i - 1] & dp[i - 2] 转移过来
            if (pre >= 10 && pre <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[size];
    }
};
