法一：暴力dfs，果然超时了
class Solution {
public:
    bool ans = false;
    vector<int> dir{1, 0, 1};
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        dfs(matrix, target, 0, 0);
        return ans;
    }
    void dfs(vector<vector<int>>& matrix, int target, int r, int c) {
        if (matrix[r][c] == target) {
            ans = true;
            return;
        }
        for (int i = 0; i <= 1 && ans == false; ++i) {
            int nr = r + dir[i];
            int nc = c + dir[i + 1];
            if (nr >= matrix.size() || nc >= matrix[0].size()) continue;
            if (matrix[nr][nc] <= target) dfs(matrix, target, nr, nc);
        }
    }
};

法二：抽象bst，很妙
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //抽象BST
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        int c = n - 1;
        while (r < m && c >= 0) {
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] > target) {
                --c;
                continue;
            }
            if (matrix[r][c] < target) {
                ++r;
                continue;
            }
        }
        return false;
    }
};
