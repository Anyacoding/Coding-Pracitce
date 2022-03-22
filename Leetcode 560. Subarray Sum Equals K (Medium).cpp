法一：前缀和加哈希表优化
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for (auto it : nums) {
            sum += it;
            //sum - (sum - k) == k
            ans += hash[sum - k];
            ++hash[sum];
        }
        return ans;
    }
};
