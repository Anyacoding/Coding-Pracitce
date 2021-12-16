法一：01背包问题
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (auto it : nums) {
            sum += it;
        }
        //如果sum不能被分为两半，则无论如和都凑不出相等的子集
        if (sum % 2 != 0) return false; 
        //目标价值
        int target = sum / 2; 
        //dp[i][j]表示从前i个数中选若干个数，是否使得这些数字的和恰好等于j。因此dp[i][j]有两种状态，true或者false。
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false)); 
        //前0个什么都装不了，但能满足刚好装够0的要求，所以给ture
        dp[0][0] = true; 
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                //看着是能装下，但不知道以前装了多少，所以从以前的状态转移过来
                if (j >= nums[i - 1]) {
                    //有两种情况，一种情况是装上nums[i - 1]且前i - 1已经装了j - nums[i - 1]，加起来刚好凑够j
                    //另一种情况是前i - 1个已经凑够j了，两种情况有一种是true则dp[i][j]为true
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
                //装不了，所以只能从前i- 1个看看能不能刚好装满j，进行转移
                else if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                //可以看作是剪枝
                if (dp[i][target] == true) {
                    return true;
                }
            }
        }
        return dp[n][target];
    }
};

法二：采用滚动数组路径压缩

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (auto it : nums) {
            sum += it;
        }
        //如果sum不能被分为两半，则无论如和都凑不出相等的子集
        if (sum % 2 != 0) return false; 
        //目标价值
        int target = sum / 2; 
        //dp[i][j]表示从前i个数中选若干个数，是否使得这些数字的和恰好等于j。因此dp[i][j]有两种状态，true或者false。
        //这里使用了滚动数组路径压缩
        vector<bool> dp(target + 1, false); 
        //dp[0][0]表示第0个数选若干个数使得数字等于0，因为没有数字可选，所以当然等于0
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = target; j >= nums[i - 1]; --j) {
                //有两种情况，一种情况是装上nums[i - 1]且前i - 1已经装了j - nums[i - 1]，加起来刚好凑够j
                //另一种情况是前i - 1个已经凑够j了，两种情况有一种是true则dp[i][j]为true
                dp[j] = dp[j - nums[i - 1]] || dp[j];
                //可以看作是剪枝
                if (dp[target] == true) {
                    return true;
                }
            }
        }
        return dp[target];
    }
};
