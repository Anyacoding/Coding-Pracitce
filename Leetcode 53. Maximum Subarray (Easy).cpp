法一:dp 未压缩版本
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        //dp[i]代表[0, i]区间最大子数组和
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int max = dp[0];
        for (int i = 1; i < n; ++i) {
            if (dp[i - 1] < 0) {
                dp[i] = nums[i];
            }
            else {
                dp[i] = dp[i - 1] + nums[i];
            }
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};

法二：压缩版本 因为dp[i]只跟dp[i - 1]有关，所以很容易压缩

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        //dp[i]代表[0, i]区间最大子数组和
        int dp = nums[0];
        int max = dp;
        for (int i = 1; i < n; ++i) {
            if (dp < 0) {
                dp = nums[i];
            }
            else {
                dp = dp + nums[i];
            }
            if (dp > max) {
                max = dp;
            }
        }
        return max;
    }
};
