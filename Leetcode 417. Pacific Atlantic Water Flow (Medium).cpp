class Solution {
public:
    //辅助方向数组
    vector<int> direction{-1, 0, 1, 0, -1};
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& can_reach, int r, int c) {
        //已经收录进来的就没必要再探索了，否则就是浪费时间
        if (can_reach[r][c] == true) {
            return;
        }
        //未知才有探索意义
        can_reach[r][c] = true;
        int x;
        int y;
        for (int i = 0; i < 4; ++i) {
            x = r + direction[i];
            y = c + direction[i + 1];
            //判断边界以及能否逆流而上
            if (x >= 0 && x < heights.size() && y >=0 && y < heights[0].size() && heights[r][c] <= heights[x][y]) {
                dfs(heights, can_reach, x, y);
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        if (heights.size() == 0 || heights[0].size() == 0)
        return ans;
        //记录边界
        int m = heights.size();
        int n =  heights[0].size();
        //太平洋逆流而上能到达的点
        vector<vector<bool>> p_can_reach(m, vector<bool>(n, false));
        //大西洋逆流而上能到达的点
        vector<vector<bool>> a_can_reach(m, vector<bool>(n, false));
        //接下来对矩阵的四条边进行遍历
        //其实就是从太平洋大西洋出发搜索能到达的点
        for (int i = 0; i < m; ++i) {
            dfs(heights, p_can_reach, i, 0);
            dfs(heights, a_can_reach, i, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(heights, a_can_reach, m - 1, i);
            dfs(heights, p_can_reach, 0, i);
        }
        //从太平洋和大西洋逆流而上都能到达的点就是所求点
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (p_can_reach[i][j] && a_can_reach[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
