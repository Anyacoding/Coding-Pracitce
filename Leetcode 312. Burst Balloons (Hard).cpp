法一：记忆化dfs，还是被卡时间了
明天再想想有没有更好的记忆化方法
class Solution {
public:
    map<vector<int>, int> map;
    int maxCoins(vector<int>& nums) {
        return dfs(nums);
    }
    int dfs(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (map.find(nums) != map.end()) {
            return map[nums];
        }
        int res = 0;
        for (auto it = nums.begin(); it < nums.end(); ++it) {
            int left = (it == nums.begin()) ? 1 : *(it - 1);
            int right = (it == nums.end() - 1) ? 1 : *(it + 1);
            int total = left * (*it) * right;
            int temp = *it;
            nums.erase(it);
            total += dfs(nums);
            res = max(res, total);
            nums.insert(it, temp);
        }
        map[nums] = res;
        return res;
    }
};
