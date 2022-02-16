法一：朴素解法，用nums.size()个桶来装就好
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int> flag(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            flag[nums[i]] = 1;
        }
        for (int i = 1; i < flag.size(); ++i) {
            if (flag[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};

法二:原地操作，常数空间
对于第 i 个数字 nums[i]，我们位置 (nums[i] - 1) % n 的位置增加 n，这样不会覆盖原数组，因为 (nums[i] - 1) % n = (nums[i] - 1 + n) % n，
这样如果最后遍历完数组，nums[i] 小于等于 n，就是数组中中消失的数字。

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int index = (nums[i] - 1) % n;
            nums[index] += n;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n) ans.push_back(i + 1);
        }
        return ans;
    }
};
