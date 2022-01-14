法一：dfs暴搜
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        dfs(sum, nums, target, 0, 0);
        return sum;
    }
    void dfs(int& sum, vector<int>& nums, const int& target, int i, int cur) {
        if (i == nums.size()) {
            if (cur == target) ++sum;
            return;
        }
        dfs(sum, nums, target, i + 1, cur + nums[i]);
        dfs(sum, nums, target, i + 1, cur - nums[i]);
    }
};

法二：dp法
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        //s为nums的所有元素的绝对值之和，由于题目保证每个元素大于等于0，故不用取绝对值
        for (auto it : nums) {
            s += abs(it); 
        }
        if (abs(target) > s) return 0;
        //dp[i][j]代表前i个元素通过组合等于j的方法个数，由于中间量的范围为[-s,s]，故对数组做一个s的右偏移
        //偏移后的dp[i][j]代表代表前i个元素通过组合等于j - s的方法个数
        vector<vector<int>> dp(n + 1, vector<int>(2 * s + 1));
        //前0个元素组合成0的方法初始化为1
        dp[0][0 + s] = 1;
        for (int i = 1; i <= n; ++i) {
            int cur = nums[i - 1];
            for (int j = 0; j <= 2 * s; ++j) {
                if (j - cur >= 0)  dp[i][j] += dp[i - 1][j - cur];
                if (j + cur <= 2 * s) dp[i][j] += dp[i - 1][j + cur];
            }
        }
        return dp[n][target + s];
    }
};
