class Solution {
public:
    int findComplement(int num) {
        long long ans = 1;
        while (true) {
            if (num >= ans) ans <<= 1;
            else return ans - num - 1;
        }
        return 0;
    }
};
