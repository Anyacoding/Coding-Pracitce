class Solution {
public:
    void backtracking(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, vector<bool>& used) {
        if (path.size() == nums.size()) {
            //level代表递归层数，当level等于nums.size() - 1时，则说明排列完成，应该push到ans里面了
            //等价于path.size() == nums.size()
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, ans, path, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        //特殊判断
        if (nums.size() == 0) {
            return ans;
        }
        //path可以看作一个栈，用来存储路径，即已经用过的数字，这样能更直观的体现回溯的思想
        int lenth = nums.size();
        vector<int> path;
        vector<bool> used(lenth, false);
        backtracking(nums, ans, path, used);
        return ans;
    }
};
