法一：诀窍是选取中位数
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid_num = nums[nums.size() / 2];
        int ans = 0;
        for (auto it : nums) {
            ans += abs(it - mid_num);
        }
        return ans;
    }
};
