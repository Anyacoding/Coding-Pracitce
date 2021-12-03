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
