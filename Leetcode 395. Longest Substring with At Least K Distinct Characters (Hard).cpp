class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) 
        return 0;
        //记录字符串中每个字符的个数
        vector<int> num(26, 0);
        for (auto it : s) {
            ++num[it - 'a'];
        }
        //递归-分治 ：遍历统计各个字符的个数 ，根据其中个数 小于 k 的字符进行分治处理
        for (int i = 0; i < s.size(); ++i) {
            if (num[s[i] - 'a'] < k) {
                int l = longestSubstring(s.substr(0, i), k);
                int r = longestSubstring(s.substr(i + 1, s.size()), k);
                return max(l, r);
            }
        }
        return s.size();
    }
};
