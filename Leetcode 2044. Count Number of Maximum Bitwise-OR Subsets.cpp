法一：二进制遍历，太妙啦！
状态压缩具体的做法就是用一个数字代表子集元素是否出现的情况；我们一般称为bitmap。
一个具体的例子如下：比如对于集合 [0,1,2,3,4,5] 中的子集 [4,3,1] 我们可以用数字 011010 来表示；bitmap的第i位代表了集合下标为i的元素出现。
如果采用了状态压缩，我们可以直接写成非递归的形式，因为bitmap最多有集合数量位1；我们可以直接从1开始遍历bitmap的所有取值范围并逐一校验。
校验的时候，需要采取状态压缩的反过程，逐位判断是否为1，也就是对应的集合元素是否被取。对符合条件的状态累计计数即可。
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0;
        int MAX = 0;
        for (const auto it : nums) {
            MAX |= it;
        }
        int n = nums.size();
        for (int bit = 1; bit < 1 << n; ++bit) {
            int res = 0;
            for (int i = 0; i < n; ++i) {
                if (1 & (bit >> i)) res |= nums[i];
                if (res == MAX) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
