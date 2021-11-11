class Solution {
public:
    //每相邻两位代表上下左右
    //例如 x = r + direction[0]  y = c + direction[0 + 1]
    //代表(r,c)这个点紧贴着的左边的点
    vector<int> direction{-1, 0, 1, 0, -1};
    //dfs实现
    int dfs(vector<vector<int>>& grid, int r, int c) {
        //递归出口，当前点是海洋时则不用继续搜索了
        if (grid[r][c] == 0) return 0;
        int area = 1;
        //当前点已统计，则将其归为海洋
        grid[r][c] = 0;
        int x, y;
        for (int i = 0; i < 4; ++i) {
            //对当前点的上下左右都进行深度优先搜索
            //若是海洋则直接返回，若是陆地则继续搜索
            x = r + direction[i];
            y = c + direction[i + 1];
            //这里有可能超越数组边界，一定要进行判断
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size())
            area += dfs(grid, x, y);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int max_size = 0;
        //grid是个二维矩阵，可以代表一张地图
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    max_size = max(max_size, dfs(grid, i, j));
                }
            }
        }
        return max_size;
    }
};
