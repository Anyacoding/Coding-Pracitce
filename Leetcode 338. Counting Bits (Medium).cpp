法一：朴素位运算
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int count = 0;
        while (count <= n) {
            int temp = count;
            int check = 1;
            int total = 0;
            for (int i = 1; i <= 32; ++i) {
                if ((check & temp) == 1) ++total;
                temp >>= 1;
            }
            ans.push_back(total);
            ++count;
        }
        return ans;
    }
};

法二：dp优化版本
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = 1 & i? dp[i - 1] + 1 : dp[i >> 1];
        }
        return dp;
    }
};
