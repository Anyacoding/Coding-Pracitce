法一：利用除答案以外的元素均出现两次，我们可以先对 nums 中的所有元素执行异或操作，得到 sum，sum 为两答案的异或值（sum 必然不为 0）。
然后取 sum 二进制表示中为 1 的任意一位 k，sum 中的第 k 位为 1 意味着两答案的第 k 位二进制表示不同。
对 nums 进行遍历，对第 k 位分别为 0 和 1 的元素分别求异或和（两答案必然会被分到不同的组），即为答案。
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2);
        int check = 0;
        for (const auto &it : nums) {
            check ^= it;
        }
        int k = -1;
        for (int i = 0; i <= 31 && k == -1; ++i) if (1 & (check >> i)) k = i;
        for (const auto &it : nums) {
            if (1 & (it >> k)) ans[0] ^= it;
            else ans[1] ^= it;
        }
        return ans;
    }
};
