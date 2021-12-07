法一：dp
动态规划的思想是，与当前状态对应的信息，可以由之前状态对应的信息递推出来。
对于此题来说，我们可以:

把一个数看作一个状态，记当前的数为i，i之前的某个数为x
把和为数i的完全平方数的最少数量看作状态对应的信息，记为dp[i]
那现在问题就变成了，具体i之前的哪个x.可以使得通过dp[x]推出dp[i]?
显然，在数i之前一定存在着许多数x使得 x+一个完全平方数等于 i,
即x+k*k=i(k=1,2,3...)，也就是x与i之间差一个完全平方数,
即dp[x]+1 = dp[i]。

所以，我们只要找到所有与i差一个完全平方数的x,然后看这些x的哪个dp[x]最小，把最小的dp[x]+1,就得到了dp[i]。
即:

作者：zhi-ai-thunder
链接：https://leetcode-cn.com/problems/perfect-squares/solution/dong-tai-gui-hua-xiang-xi-jiang-jiang-di-0rol/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 99999);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j]  + 1);
            }
        }
        return dp[n];
    }
};
