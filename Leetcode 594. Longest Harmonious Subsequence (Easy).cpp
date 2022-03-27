法一：哈希表存储
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int, int> hash;
        int ans = 0;
        for (auto it : nums) {
            ++hash[it];
        }
        for (auto cur = ++hash.begin(), pre = hash.begin(); cur != hash.end(); ++cur, ++pre) {
            if ((*cur).first - (*pre).first == 1)
            ans = max(ans, (*cur).second + (*pre).second);
        }
        return ans;
    }
};
