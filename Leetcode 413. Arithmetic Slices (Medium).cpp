法一：自己想的暴力法
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

法二：标准动态规划
解题思路
定义dp[i]表示加入第i个数字，对答案的贡献值。
那么答案累加这些个贡献
我们会发现
如果
1 2 3
加入一个4
那么有3种组合
1 2 3
2 3 4
1 2 3 4
新加入的nums[i]=4的贡献是3-1=2
在加入一个5
1 2 3
2 3 4
3 4 5
1 2 3 4
2 3 4 5
1 2 3 4 5
新加入的num[i]=5的贡献是6-3=3

我们会发现如果一个数和前面的2个数成等差，那么他的贡献就是dp[i-1]+1
当2 4 6的时候加8也是同理

作者：jiao-chun-peng
链接：https://leetcode-cn.com/problems/arithmetic-slices/solution/dong-tai-gui-hua-by-jiao-chun-peng-oine/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int ans = 0;
        vector<int> dp(n, 0);
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1; //状态转移方程
                ans += dp[i];
            }
        }
        return ans;
    }
};

