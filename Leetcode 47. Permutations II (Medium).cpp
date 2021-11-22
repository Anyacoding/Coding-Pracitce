
class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& path, vector<bool>& used, set<vector<int>>& bucket) {
        if (path.size() == nums.size()) {
            bucket.insert(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, path, used, bucket);
                used[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        vector<bool> used(nums.size(), false);
        vector<int> path;
        set<vector<int>> bucket;
        for (int i = 0; i < nums.size(); ++i) {
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, path, used, bucket);
            used[i] = false;
            path.pop_back();
        }
        for (auto it : bucket) {
            ans.push_back(it);
        }
        return ans;
    }
};
