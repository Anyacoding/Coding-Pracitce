class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long m = n;
        //错位异或低位全是1，加1之后二进制中只有一个1
        //再利用n & (n - 1) 可以去除 n 的位级表示中最低的那一位1，则二进制为0，判断是不是0就行
        m = (m ^ (m >> 1)) + 1;
        m = m & (m - 1);
        if (!m) return true;
        return false;
    }
};
