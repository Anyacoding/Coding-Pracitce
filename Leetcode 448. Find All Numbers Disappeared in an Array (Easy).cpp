法一：朴素解法，用nums.size()个桶来装就好
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int> flag(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            flag[nums[i]] = 1;
        }
        for (int i = 1; i < flag.size(); ++i) {
            if (flag[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};
