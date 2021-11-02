class Solution {
public:
    bool judgeSquareSum(int c) {
        bool flag = false;
        for (int i = 0, j = sqrt(c); i <= sqrt(c) && j >= 0;) {
            if (pow(i, 2) + pow(j, 2) == c) {
                flag = true;
                break;
            }
            else if (pow(i, 2) + pow(j, 2) > c) {
                --j;
            }
            else {
                ++i;
            }
        }
        return flag;
    }
};
