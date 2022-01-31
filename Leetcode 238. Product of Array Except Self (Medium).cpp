法一：乘积 = 当前数左边的乘积 * 当前数右边的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int temp = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            temp = temp * nums[i + 1];
            ans[i] = ans[i] * temp;
        }
        return ans;
    }
};
