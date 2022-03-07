法一：先把所有端点从小到大排列，不同的端点优先排左端点，重复的端点则按照高度从小到大排
然后用优先队列维护高度，遇到左端点就加入高度，遇到右端点就删除该高度
具体思路可参考力扣题解，非常妙的一道题
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        // map<int, int> x;
        // for (const auto& it : buildings) {
        //     x[it[0]] = -it[2];
        //     x[it[1]] = it[2];
        // }
        vector<pair<int, int>> x;
        for (const auto& it : buildings) {
            x.push_back({it[0], -it[2]});
            x.push_back({it[1], it[2]});
        }
        sort(x.begin(), x.end(), [](auto a, auto b) -> bool {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        multiset<int, greater<int>> heap;
        heap.insert(0);
        int cur = 0;
        for (auto [point, high] : x) {
            //说明是左端点
            if (high < 0) {
                heap.insert(-high);
            }
            else {
                //新技巧，避免一次性把目标值全部删除
                auto pos = heap.find(high);
                heap.erase(pos);
            }
            high = *heap.begin();
            if (cur != abs(high)) {
                ans.push_back(vector<int>{point, high});
                cur = high;
            }
        }
        return ans;
    }
};
