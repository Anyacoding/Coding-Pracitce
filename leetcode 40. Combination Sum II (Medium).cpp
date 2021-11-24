class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& comb, vector<bool>& used, int index, int target, int sum) {
        if (sum == target) {
            ans.push_back(comb);
            return;
        }
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            //剪枝
            //因为一开始就对candidates排序了，保证了相同数字在相邻位置
            //只有当candidates[i] == candidates[i - 1]时才进行used判断
            // used[i - 1] == true，说明同一树支candidates[i - 1]使用过,这个是可以的，可以继续向下dfs
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过，这个是打咩的，因为这样就有可能出现相同的组合
            //必须保证在每一层的元素都不相同，这样子得出来的组合就不会有元素上完全相同的情况了
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
            used[i] = true;
            sum += candidates[i];
            comb.push_back(candidates[i]);
            dfs(ans, candidates, comb, used, i + 1, target, sum);
            sum -= candidates[i];
            comb.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if (candidates.size() == 0) return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        vector<bool> used(candidates.size(), false);
        int sum = 0;
        dfs(ans, candidates, comb, used, 0, target, sum);
        return ans;
    }
};
