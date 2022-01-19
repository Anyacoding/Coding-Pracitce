法一：记忆化dfs，还是被卡时间了
明天再想想有没有更好的记忆化方法
class Solution {
public:
    map<vector<int>, int> map;
    int maxCoins(vector<int>& nums) {
        return dfs(nums);
    }
    int dfs(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (map.find(nums) != map.end()) {
            return map[nums];
        }
        int res = 0;
        for (auto it = nums.begin(); it < nums.end(); ++it) {
            int left = (it == nums.begin()) ? 1 : *(it - 1);
            int right = (it == nums.end() - 1) ? 1 : *(it + 1);
            int total = left * (*it) * right;
            int temp = *it;
            nums.erase(it);
            total += dfs(nums);
            res = max(res, total);
            nums.insert(it, temp);
        }
        map[nums] = res;
        return res;
    }
};
法二：区间dp，超级难想我去
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> points(n + 2, 0);
        //在左右两边都加上虚拟气球
        points[0] = 1;
        points[n + 1] = 1;
        for (int i = 0; i < n; ++i) {
            points[i + 1] = nums[i];
        }
        //dp[i][j]表示在开区间(i, j)内戳气球获得的最大硬币数
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        //开区间长度
        for (int len = 3; len <= n + 2; ++len) {
            //左端点,这个循环本质上就是让开区间不断往右移动，当左端点等于倒数第len个位置时，开区间就无法再向右移动了
            for (int j = 0; j <= n + 2 - len; ++j) {
                //在这个开区间里，有len - 2种戳法，迭代出哪一种戳法是得到最多硬币的，即dp[j][j + len - 1]
                for (int k = j + 1; k < j + len - 1; ++k) {
                    int left = dp[j][k];
                    int right = dp[k][j + len - 1];
                    int sum = left + right + points[k] * points[j] * points[j + len - 1];
                    dp[j][j + len - 1] = max(sum, dp[j][j + len - 1]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
