法一：阶乘拆分找规律
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
