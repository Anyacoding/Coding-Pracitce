class Solution {
public:
    //辅助方向数组
    vector<int> direction{-1, 0, 1, 0, -1};
    //调了一天，最后超时的原因竟然是因为used数组没有传引用，真是汗流浃背
    //导致used每一次传递时都调用了构造函数导致超时,寄！
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& used, int& pos, bool& ans, string& word, int r, int c) {
        //pos已经到达word的末尾，说明在图中已经找到了路径，可以返回true
        if (pos == word.size()) {
            ans = true;
            return;
        }
        if (ans == true) {
            return;
        }
        int x;
        int y;
        for (int i = 0; i < 4; ++i) {
            x = r + direction[i];
            y = c + direction[i + 1];
            //检查边界条件并进行判断
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
                if (used[x][y] == false && board[x][y] == word[pos]) {
                    used[x][y] = true;
                    ++pos;
                    dfs(board, used, pos, ans, word, x, y);
                    --pos;
                    used[x][y] = false;
                }
            }
        }
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        //首先进行特殊情况排除
        if (word.size() == 0) return true;
        //状态记录数组
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        int pos = 0;
        bool ans = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (used[i][j] == false && board[i][j] == word[pos]) {
                    used[i][j] = true;
                    ++pos;
                    dfs(board, used, pos, ans, word, i, j);
                    --pos;
                    used[i][j] = false;
                }
            }
        }
        return ans;
    }
};
