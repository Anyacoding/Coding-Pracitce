法一：预处理积分图捏
class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix): sum(matrix.size(), vector<int>(matrix[0].size())) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    sum[i][j] = matrix[i][j];
                    continue;
                }
                //计算每行的前缀和
                sum[i][j] = sum[i][j - 1] + matrix[i][j];
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //从上一行同一列继承前缀形成积分
                sum[i][j] += sum[i - 1][j];
            }
        }
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << sum[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sum[row2][col2];
        int flag = 0;
        if (row1 - 1 >= 0) {
            ans -= sum[row1 - 1][col2];
            ++flag;
        }
        if (col1 - 1 >= 0) {
            ans -= sum[row2][col1 - 1];
            ++flag;
        }
        if (flag == 2) ans += sum[row1 - 1][col1 - 1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
