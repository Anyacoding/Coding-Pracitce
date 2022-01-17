法一：分治法
这题建议看题解惹，呜呜，数学解法太妙惹
class Solution {
public:
    unordered_map<int,vector<int>> map;
    vector<int> beautifulArray(int N) {
        vector<int> ans(N, 0);
        int index = 0;
        if (map.find(N) != map.end()) {
            return map[N];
        }
        if (N != 1) {
            for (auto x : beautifulArray((N + 1) / 2)) {
                ans[index++] = 2 * x - 1;
            }
            for (auto x : beautifulArray(N / 2)) {
                ans[index++] = 2 * x;
            }
        }
        else {
            ans[0] = 1;
        }
        map[N] = ans;
        return ans;
    }
};
