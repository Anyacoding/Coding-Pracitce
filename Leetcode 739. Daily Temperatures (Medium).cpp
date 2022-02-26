法一：单调栈通过维持栈内值的单调递增（递减）性，在整体 O(n) 的时间内处理需要大小比较的
问题。
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (true) {
                if (s.empty() || temperatures[i] <= temperatures[s.top()]) {
                    s.push(i);
                    break;
                }
                else if (temperatures[i] > temperatures[s.top()]) {
                    int index = s.top();
                    s.pop();
                    ans[index] = i - index;
                }
            }
        }
        return ans;
    }
};
