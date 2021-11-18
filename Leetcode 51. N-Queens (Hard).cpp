class Solution {
public:
    bool JudgeEandN(vector<string>& board, int r, int c) {
        //进行边界判断,若越界则该条路没有皇后
        if (r < 0 || r >= board.size() || c < 0 || c >= board.size()) return false;
        if (board[r][c] == 'Q') return true;
        //向左斜上方探索
        if (JudgeEandN(board, r -1, c - 1) == true) {
            return true;
        }
        return false;
    }

    bool JudgeWandN(vector<string>& board, int r, int c) {
        //进行边界判断,若越界则该条路没有皇后
        if (r < 0 || r >= board.size() || c < 0 || c >= board.size()) return false;
        if (board[r][c] == 'Q') return true;
        //向右斜上方探索
        if (JudgeEandN(board, r - 1, c + 1) == true) {
            return true;
        }
        return false;
    }

    bool JudgeWandS(vector<string>& board, int r, int c) {
        //进行边界判断,若越界则该条路没有皇后
        if (r < 0 || r >= board.size() || c < 0 || c >= board.size()) return false;
        if (board[r][c] == 'Q') return true;
        //向右斜下方探索
        if (JudgeEandN(board, r + 1, c + 1) == true) {
            return true;
        }
        return false;
    }

    bool JudgeEandS(vector<string>& board, int r, int c) {
        //进行边界判断,若越界则该条路没有皇后
        if (r < 0 || r >= board.size() || c < 0 || c >= board.size()) return false;
        if (board[r][c] == 'Q') return true;
        //向左斜下方探索
        if (JudgeEandN(board, r + 1, c - 1) == true) {
            return true;
        }
        return false;
    }

    void dfs(vector<vector<string>>& ans, vector<string>& board, vector<bool>& hang, vector<bool>& lie, int r, int c) {
        //进行边界判断
        if (r < 0 || r >= board.size() || c < 0 || c >= board.size()) return;
        //判断行和列上是否已经存在皇后
        if (lie[c] == true) return;
        //判断斜线上是否已经存在皇后
        //经过调试说明这个函数有点问题
        //确实有问题
        //if (JudgeEandN(board, r, c) == true || JudgeWandN(board, r, c) == true) return;
        //用数组判断对角线完美通过，程序上面写的四个判断对角线函数的问题还没排查出来，是日后学习的重要反例和研究材料
        for (int i = r, j = c; i >= 0 && i < board.size() && j >= 0 && j < board.size(); --i, --j) {
            if (board[i][j] == 'Q') return;
        }//探索左上角是否有皇后
        for (int i = r, j = c; i >= 0 && i < board.size() && j >= 0 && j < board.size(); --i, ++j) {
            if (board[i][j] == 'Q') return;
        }//探索右上角是否有皇后
        lie[c] = true;
        board[r][c] = 'Q';
        //皇后已经摆满了
        if (r == board.size() - 1) {
            ans.push_back(board);
        }
        for (int i = 0; i < board.size(); ++i) {
            dfs(ans, board, hang, lie, r + 1, i);
        }
        lie[c] = false;
        board[r][c] = '.';
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        //标记数组，用来判断行列以及斜线上是否已经有皇后了
        vector<bool> hang(n, false);
        vector<bool> lie(n, false);
        for (int i = 0; i < n; ++i) {
            dfs(ans, board, hang, lie, 0, i);
        }
        return ans;
    }
};
