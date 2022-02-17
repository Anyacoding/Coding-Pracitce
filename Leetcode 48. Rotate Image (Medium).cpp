class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //转置然后镜像对称
        int n = matrix.size();
        int temp = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int front = 0, back = n - 1; front < back; ++front, --back) {
                //swap(matrix[i][front], matrix[i][back]);
                temp = matrix[i][front];
                matrix[i][front] = matrix[i][back];
                matrix[i][back] = temp;
            }
        } 
    }
};
