class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int ans = 0;
        int count = 2;
        vector dp(nums.size(), -99999); //状态数组，记录第i个数字和第i-1个数字的差，初始值设为一个不可能的值，防止出现[1,1,1]重复计数的情况
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = nums[i] - nums[i - 1];
            if (dp[i] == dp[i - 1]) {
                ++count;
            }
            //dp[i] != dp[i - 1]
            else {       
                for (int sum = count - 2; sum >= 0; --sum) {
                    ans = ans + sum;
                }
                count = 2;
            }
        }
        if (count >= 3) {
            for (int sum = count - 2; sum >= 0; --sum) {
                ans = ans + sum;
            }
        }
        return ans;
    }
};
