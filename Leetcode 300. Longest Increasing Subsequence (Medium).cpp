class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1; //如果只有一个元素那子序列长度为1
        int max_len = -99999;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
           for (int j = 0; j < i; ++j) {
               if (nums[i] > nums[j]) {
                   dp[i] = max(dp[j] + 1, dp[i]);
               }
           }
           max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
