法一：贪心法很容易过了
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        int ans = 1;
        int temp = pairs[0][1];
        for (int i = 1; i < n; ++i) {
            if (pairs[i][0] > temp) {
                ++ans;
                temp = pairs[i][1];
            }
        }
        return ans;
    }
};

法二：dp法，在这里效率不如贪心
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        //dp[i]可以表示以 i 结尾的、最长子序列长度
        vector<int> dp(n, 1);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            cur = max(cur, dp[i]);
        }
        return cur;
    }
};
