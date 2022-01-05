法一：贪心算法，题解可参考代码随想录呜呜
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int prediss = 0; //先前的差值
        int curdiss = 0; //现在的差值
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            curdiss = nums[i] - nums[i - 1];
            if (curdiss > 0 && prediss <= 0 || curdiss < 0 && prediss >= 0) {
                ++ans;
                prediss = curdiss;
            }
        }
        return ans;
    }
};
