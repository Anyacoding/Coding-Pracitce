class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >=grid.size() || c < 0 || c >=grid[0].size() || grid[r][c] == 2) return;
        if (grid[r][c] == 0) {
            points.push(pair<int, int>(r, c));
            return;
        }
        grid[r][c] = 2;
        //向左
        dfs(points, grid, r, c - 1);
        //向右
        dfs(points, grid, r, c + 1);
        //向上
        dfs(points, grid, r - 1, c);
        //向下
        dfs(points, grid, r + 1, c);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> points;
        bool flag = true;
        //用dfs找到其中一个岛屿，并将1全部染色成2
        //并将环绕该岛屿的一圈0收入队列中，当作出发层，也就是第一层
        for (int i = 0; i < m; ++i) {
            if (flag == false) break;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(points, grid, i, j);
                    flag = false;
                    break;
                }
            }
        }
        //利用bfs寻找最短路径
        int x, y;
        int level = 0;
        //相当于二叉树的层序遍历
        while(points.empty() != true) {
            ++level;
            int n_points = points.size();
            //将该层中的点数都向外进行扩展，形成新的一层，若新的一层中有某一点是1，说明当前拓展层数即为最短路径
            while (n_points) {
                pair<int, int> temp;
                temp = points.front();
                int r = temp.first;
                int c = temp.second;
                points.pop();
                //只进行--n_points而不进行++n_points是因为pop消耗的是本层的点数，而push增加的是下一层的点数，与当前层无关
                //所以不进行++n_points操作
                --n_points;
                for (int k = 0; k < 4; ++k) {
                    x = r + direction[k];
                    y = c + direction[k + 1];
                    //边界判断
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != 2) {
                        if (grid[x][y] == 1) {
                            return level;
                        }
                        points.push({x, y});
                        //将走过的地方标记为2，是为了防止拓展点时是向内拓展而非向外拓展，即避免走回头路
                        grid[x][y] = 2;
                    }
                }
            }

        }
        return level;
    }
};
