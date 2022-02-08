法一：我们可以利用 x ∧ x = 0 和 x ∧ 0 = x 的特点，将数组内所有的数字进行按位异或。出现两次
的所有数字按位异或的结果是 0，0 与出现一次的数字异或可以得到这个数字本身。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto &num : nums) {
            ans ^= num;
        }
        return ans;
    }
};
