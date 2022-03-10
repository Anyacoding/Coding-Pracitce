法一:采取最大堆来维护滑动窗口最大值，擦边过了
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int, greater<int>> bucket;
        for (int i = 0; i < k; ++i) bucket.insert(nums[i]);
        for (int i = 0, j = i + k - 1; ;) {
            ans.push_back(*bucket.begin());
            ++j;
            if (j >= nums.size()) break;
            auto it = bucket.find(nums[i]);
            bucket.erase(it);
            bucket.insert(nums[j]);
            ++i;
            
        }
        return ans;
    }
};
