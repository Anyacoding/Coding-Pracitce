class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        //记录出现最多的频次
        int maxcount = 0;
        for (auto data : nums) {
            maxcount = max(maxcount, ++count[data]);
        }
        vector<vector<int>> basket(maxcount + 1);
        for (const auto &it : count) {
            basket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for (auto it = basket.end() - 1; it >= basket.begin() && k != 0; --it) {
            for (auto i = (*it).begin(); i < (*it).end() && k != 0; ++i) {
                ans.push_back((*i));
                --k;
            }
        }
        return ans;
    }
};
