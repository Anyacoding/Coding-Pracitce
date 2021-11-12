class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int r, int c) {
        if (isConnected[r][c] == 0) return;
        //当把一个城市收录进来，由于是双向奔赴的，所以一次性消除两个点
        isConnected[r][c] = 0;
        isConnected[c][r] = 0;
        for (int i = 0; i < isConnected[r].size(); ++i) {
            if (isConnected[r][i] == 1) {
                //神来之笔，如果是dfs(isConnected, r, i)则是错误的
                //这里把i放前面的意义是更新出发结点，才能不断往深处探索
                dfs(isConnected, i, r);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0 || isConnected[0].size() == 0) return 0;
        int num = 0;
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected[i].size(); ++j) {
                if (isConnected[i][j] == 1) {
                    dfs(isConnected, i, j);
                    ++num;
                }
            }
        }
        return num;
    }
};
