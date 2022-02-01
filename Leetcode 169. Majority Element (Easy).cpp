法一：思路很简单，排序后多数一定出现在中间位置
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

法二：摩尔投票法
投票法是遇到相同的则票数 + 1，遇到不同的则票数 - 1。
且“多数元素”的个数> ⌊ n/2 ⌋，其余元素的个数总和<= ⌊ n/2 ⌋。
因此“多数元素”的个数 - 其余元素的个数总和 的结果 肯定 >= 1。
这就相当于每个“多数元素”和其他元素 两两相互抵消，抵消到最后肯定还剩余至少1个“多数元素”。

无论数组是1 2 1 2 1，亦或是1 2 2 1 1，总能得到正确的候选人。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == ans) {
                ++cnt;
            }
            else {
                --cnt;
                if (cnt == 0) {
                    ans = nums[i];
                    cnt = 1;
                }
            }
        }
        return ans;
    }
};
