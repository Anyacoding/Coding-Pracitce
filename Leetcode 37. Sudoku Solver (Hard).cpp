class Solution {
public:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9]; //可以把9x9的图看作3x3的方格图，每个大方格里有9个数字，例如[0][0][0] = true代表最左上角那个大方格里1已经被用过了
    vector<pair<int, int>> space; //用来记录需要填数字的点
    bool flag = false;
    void DFS(vector<vector<char>>& board, int pos) {
        if (pos == space.size()) {
            flag = true;
            return;
        }
        auto [r, c] = space[pos];
        for (int data = 0; data < 9 && !flag; ++data) {
            if (line[r][data] == false && column[c][data] == false && block[r / 3][c / 3][data] == false) {
                board[r][c] = data + 1 + '0';
                line[r][data] = column[c][data] = block[r / 3][c / 3][data] = true;
                DFS(board, pos + 1);
                line[r][data] = column[c][data] = block[r / 3][c / 3][data] = false;
            }
        }
    }
    //if (hang[r][data] == false && column[c][data] == false && block[r / 3][c / 3][data] == false)
    void solveSudoku(vector<vector<char>>& board) {
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int data = board[i][j] - '0'; //将字符转化为int
                    line[i][data - 1] = true;
                    column[j][data - 1] = true;
                    block[i / 3][j / 3][data - 1] = true;
                }
                //就是要填数字的地方
                else {
                    pair<int, int> p(i, j);
                    space.push_back(p);
                }
            }
        }
        DFS(board, 0);
    }
};
