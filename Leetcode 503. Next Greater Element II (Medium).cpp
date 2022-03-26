法一：强大的单调栈
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            while (!s.empty() && num > nums[s.top()]) {
                ans[s.top()] = num;
                s.pop();
            }
            if (i < n) s.push(i);
        }
        return ans;
    }
};
