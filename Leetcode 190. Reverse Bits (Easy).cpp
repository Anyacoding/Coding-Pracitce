法一：位运算
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //最开始的这个1在32次左移后会被丢弃掉
        uint32_t ans = 1; 
        for (int i = 1; i <= 32; ++i) {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};
