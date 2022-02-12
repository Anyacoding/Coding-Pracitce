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
法二：异或求消失的数，利用 x ∧ x = 0 和 x ∧ 0 = x 的特点，将数组内所有的数字进行按位异或。出现两次
的所有数字按位异或的结果是 0，0 与出现一次的数字异或可以得到这个数字本身。我们手动使得nums中出现的元素出现两次，那么消失的元素就只出现一次
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ans ^= i + 1;
            ans ^= nums[i];
        }
        return ans;
    }
};
