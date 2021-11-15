class Solution {
public:
    void dfs(vector<int>& path, vector<int> used, vector<vector<int>>& ans, int k, int n) {
        //组合数已经完成，可以塞入ans中了
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }
            for (int i = 1; i <= n; ++i) {
                if (used[i] == false) {
                    used[i] = true;
                    path.push_back(i);
                    dfs(path, used, ans, k, n); 
                    //这里不进行used的回溯是为了每一个分支都产生一个新的状态，即为了不出现在3，3情况下  输出123和132的不合理答案
                    //而且used数组我们不是引用传递而是值传递是因为在进行第一层的组合数构建时
                    //我们要以不同的数字为开头进行尝试，为了不让新的分支状态影响到最顶层的数字初始选择
                    //所以选择了这种做法，当然代价是性能的极大损耗，这显然不是最优解
                    path.pop_back();
                }
            }  
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (k == 0) return ans;
        vector<int> used(n + 1, false);
        vector<int> path;
        for (int i = 1; i <= n; ++i) {
            used[i] = true;
            path.push_back(i);
            dfs(path, used, ans, k, n);
            //顶层构造不回溯used是因为之前已经选择过的数字保证不出现在之后的组合数中
            //比如一开始顶层构造是以1为开头的组合数，在下一轮中以2为开头的组合数不能再使用1了
            //即已选择过的数不能再次使用
            path.pop_back();
        }
        return ans;
    }
};
