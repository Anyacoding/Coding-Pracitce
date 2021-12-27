法一：dp 主要是要会把环形数组拆成两个队列即可，即第一个房子和最后一个房子只能抢一个，比较出最大值即可
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //dp[i]代表第i天能偷到的最大金额数
        vector<int> dp (n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            //i == n偷不了，因为一开始默认了一号屋子会抢
            if (i == n) {
                dp[i] = dp[i - 1];
                continue;
            }
            //要么不偷要么偷，不偷的话状态转移自dp[i - 1], 偷的话状态转移自dp[i - 2] + nums[i];
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        vector<int> sq (n + 1, 0);
        sq[1] = 0;
        for (int i = 2; i <= n; ++i) {
            //i == n可以偷，因为一开始默认了一号屋子不会抢
            //要么不偷要么偷，不偷的话状态转移自dp[i - 1], 偷的话状态转移自dp[i - 2] + nums[i];
            sq[i] = max(sq[i - 1], sq[i - 2] + nums[i - 1]);
        }
        return max(dp[n], sq[n]);
    }
};
