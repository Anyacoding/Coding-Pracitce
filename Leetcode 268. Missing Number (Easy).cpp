法一：高斯求和
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int gauss = (1 + n) * n / 2;
        int sum = 0;
        for (const auto &it : nums) sum += it;
        return gauss - sum;
    }
};
