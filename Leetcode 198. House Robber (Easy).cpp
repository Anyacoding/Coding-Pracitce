class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0]; //dp[i]表示第i个房间能抢到的最大金额,因为第一个房间只有一种情况是最大金额，那就是直接抢，所有直接赋值为nums[0]
        for (int i = 2; i <= n; ++i) {
            //每个房间都有两种抢劫方式，抢或者不抢，不抢的话最大金额就是dp[i - 1]
            //抢的话就是dp[i - 2] + nums[i - 1] ,因为第i - 1间也抢了的话就报警了,这里注意nums是从下标0开始的,而dp我们默认是从下标1开始的
            //因为没有第0间的房间
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]); //状态转移方程
        }
        return dp[n];
    }
};
