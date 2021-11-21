class Solution {
public:
    int m, n;
    void dfs_fixed(vector<vector<char>>& board, int r, int c) {
        //不能传used数组辅助判断，否则会栈溢出
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'A';
        dfs_fixed(board, r + 1, c);//向上探索
        dfs_fixed(board, r - 1, c);//向下探索
        dfs_fixed(board, r, c + 1);//向左探索
        dfs_fixed(board, r, c - 1);//向右探索
    }
    void solve(vector<vector<char>>& board) {
        //vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        m = board.size();
        n = board[0].size();
        for (int r = 0; r < board.size(); ++r) {
            dfs_fixed(board, r, 0);
            dfs_fixed(board, r, n - 1);
        }
        for (int c = 0; c < board[0].size(); ++c) {
            dfs_fixed(board, 0, c);
            dfs_fixed(board, m - 1, c);
        }
        //将中间的未固定的'O'染色
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
