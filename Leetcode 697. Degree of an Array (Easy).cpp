class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> hash;
        unordered_map<int, pair<int, int>> index;
        vector<int> temp;
        int ans = INT_MAX;
        int count = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.count(nums[i]) == 0) {
                index[nums[i]].first = index[nums[i]].second = i;
            }
            else if (hash.count(nums[i]) != 0) {
                index[nums[i]].second = i;
            }
            ++hash[nums[i]];
            count = max(count, hash[nums[i]]);
        }
        //cout << count;
        for (auto [val, frequency] : hash) {
            if (frequency == count) {
                ans = min(ans, index[val].second - index[val].first + 1);
                cout << val << " " << index[val].second << " " << index[val].first << endl;
            }
        }
        return ans;
    }
};
