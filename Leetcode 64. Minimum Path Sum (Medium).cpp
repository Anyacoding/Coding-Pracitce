法一：第一个就想到用DFS，但是超时了捏
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int& ans, int r, int c, int sum) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return; //越界直接返回
        sum = sum + grid[r][c]; //不越界则把当前权值加上
        //到达右下角
        if (r == grid.size() -  1 && c == grid[0].size() - 1) {
            ans = min(ans, sum); 
        }
        //向下右两个方向探索
        dfs(grid, ans, r, c + 1, sum);
        //dfs(grid, ans, r, c - 1, sum);
        dfs(grid, ans, r + 1, c, sum);
        //dfs(grid, ans, r - 1, c, sum);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int ans = 99999;
        dfs(grid, ans, 0, 0, 0);
        return ans;
    }
};

法二：二维动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp (grid.size(), vector<int>(grid[0].size(), 99999)); //对dp数组进行一个初始的化
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                //左上角做特殊处理
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } 
                //第一行除左上角外做特殊处理
                else if (i == 0 && j != 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                //第一列除左上角外做特殊处理
                else if (i != 0 && j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                //其余都可以套用状态转移方程
                else {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
                }
            }
        }
        int m = grid.size() - 1;
        int n = grid[0].size() - 1;
        return dp[m][n];
    }
};
