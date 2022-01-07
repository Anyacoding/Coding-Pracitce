法一：dfs暴搜
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        dfs(sum, nums, target, 0, 0);
        return sum;
    }
    void dfs(int& sum, vector<int>& nums, const int& target, int i, int cur) {
        if (i == nums.size()) {
            if (cur == target) ++sum;
            return;
        }
        dfs(sum, nums, target, i + 1, cur + nums[i]);
        dfs(sum, nums, target, i + 1, cur - nums[i]);
    }
};
