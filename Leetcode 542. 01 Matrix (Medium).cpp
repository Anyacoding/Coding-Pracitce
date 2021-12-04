法一：dp动态规划
我们发现 dp[i][j]dp[i][j] 是由其上下左右四个状态来决定，无法从一个方向开始递推！
因此我们分别从四个角开始递推，就分别得到了位于「左上方、右上方、左下方、右下方」距离 (i, j) 的最近的 0 的距离，取 min 即可；
从四个角开始的 4 次递推，其实还可以优化成从任一组对角开始的 2 次递推，比如只写从左上角、右下角开始递推就行了
第一次递推dp[i][j]取左方和上方的最优解，第二次递推取右方和下方的最优解，两次递推就可得到四个方向中的最优解
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        int m = mat.size(); //记录矩阵大小
        int n = mat[0].size(); //记录矩阵大小
        vector<vector<int>>dp (m, vector<int>(n, 99999));
        //从左上到右下进行一次动态搜索，再从右下到左上进行一次动态搜索。两次动态搜索即可完成四个方向上的查找。
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dp[i][j] = mat[i][j];
                    continue;
                }
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
                if (i > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (mat[i][j] == 0) {
                    dp[i][j] = mat[i][j];
                    continue;
                }
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
                if (i < m - 1) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
            }
        }
        return dp;
    }
};
