class Solution {
public:
    string frequencySort(string s) {
        map<char, int> count;
        int max_count = 0;
        //记录每个字母出现的频次
        for (auto data : s) {
            max_count = max(max_count, ++count[data]);
        }
        string ans;
        vector<string> bucket(max_count + 1);
        //用桶排序下标表示频次，往里面拼接字母
        for (auto it : count) {
            for (int i = it.second; i > 0; --i) {
                //某字母出现n次就拼接n次
                bucket[it.second] += it.first;
            }
        }
        //按出现频次降序拼接字符串
        for (int i = max_count; i >= 0; --i) {
            ans += bucket[i];
        }
        return ans;
    }
};
