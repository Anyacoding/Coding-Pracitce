法一：二维dp
对于在矩阵内搜索正方形或长方形的题型，一种常见的做法是定义一个二维 dp 数组，其中
dp[i][j] 表示满足题目条件的、以 (i, j) 为右下角的正方形或者长方形的属性。对于本题，则表示
以 (i, j) 为右下角的全由 1 构成的最大正方形面积。如果当前位置是 0，那么 dp[i][j] 即为 0；如果
当前位置是 1，我们假设 dp[i][j] = k，其充分条件为 dp[i-1][j-1]、dp[i][j-1] 和 dp[i-1][j] 的值必须
都不小于 (k − 1)，否则 (i, j) 位置不可以构成一个边长为 k 的正方形。同理，如果这三个值中的
的最小值为 k − 1，则 (i, j) 位置一定且最大可以构成一个边长为 k 的正方形。

class Solution {
public:
    vector<int> direction = {0, -1, -1, 0}; //左方，左上角，上方三个方向
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int Max = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    int Min = 99999;
                    int x, y;
                    for (int k = 0; k < 3; ++k) {
                        x = i + direction[k];
                        y = j + direction[k + 1];
                        //边界判断,如果没有越界
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            Min = min(Min, dp[x][y]);
                        }
                        //如果越界了
                        else {
                            Min = min(Min, 0);
                        }
                    }
                    dp[i][j] = Min + 1;
                    Max = max(Max, dp[i][j]);
                }
            }
        }
        return Max * Max;
    }
};
