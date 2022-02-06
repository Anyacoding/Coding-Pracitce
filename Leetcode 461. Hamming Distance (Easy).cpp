法一:位运算
class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int ans = 0;
        while (diff != 0) {
            ans += diff & 1;
            diff >>= 1;
        }
        return ans;
    }
};
