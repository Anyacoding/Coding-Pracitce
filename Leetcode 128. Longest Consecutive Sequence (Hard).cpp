法一：直接逃课，利用红黑树维护即可，不断更新最长连续序列
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = 0;
        set<int> hash;
        for (const auto it : nums) {
            hash.insert(it);
        }
        int pre = *hash.begin();
        int temp = 1;
        for (const auto cur : hash) {
            if (cur - pre == 1) {
                pre = cur;
                ++temp;
            }
            else {
                temp = 1;
                pre = cur;
            }
            ans = max(ans, temp);
            cout << cur << " ";
        }
        return ans;
    }
};
