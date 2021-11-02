class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        //带输出字符串
        string ans;
        //当前字符长度
        int lenth = 0;
        for (auto it = dictionary.begin(); it != dictionary.end();) {
            int i = 0, j = 0;
            int num = 0;
            while (i != s.size() && j != (*it).size()) {
                if (s[i] == (*it)[j]) {
                    num++;
                    ++i;
                    ++j;
                }
                else {
                    ++i;
                }
            }
            //灵魂语句，因为没有这句话wr了四次，主要思想是退出时，若数组字符串没有遍历完，说明还有尾巴
            //则必定不可能和目标字符串对应的上，因为目标字符串已经没有字符可以和尾巴对应了
            if (j != (*it).size()) {
                num = -1;
            }
            //如果当前字符串长度更长，则进行更新
            if (num > lenth) {
                lenth = num;
                ans = *it;
            }
            //如果长度相等，则比较字符序
            else if (num == lenth && (*it) < ans) {
                ans = *it;
            }
            ++it;
        }
        return ans;
    }
};
