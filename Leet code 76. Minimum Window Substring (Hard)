class Solution {
public:
    string minWindow(string s, string t) {
        //记录T中每个字母需要的个数
        vector<int> chars(128, 0);
        //记录T中哪些字母存在
        vector<bool> flag(128, false);
        //记录T中字符情况
        for (int i = 0; i < t.size(); ++i) {
            flag[t[i]] = true;
            ++chars[t[i]];
        }

        int l = 0, r = 0, minsize = s.size() + 1, min_l = 0;
        int cnt = 0;
        for (int r = 0; r < s.size(); ++r) {
            //是T中存在的字符
            if (flag[s[r]]) {
                //当前存在字符还是有效字符
                if (--chars[s[r]] >= 0) {
                    ++cnt;
                }
                //当前窗口内已含有T中所以字符
                while (cnt == t.size()) {
                    //更新当前最小字符长度
                    if (r - l + 1 < minsize) {
                        minsize = r - l + 1;
                        min_l = l;
                    }
                    //移动左边界继续探索
                    //能进入if说明左边界是有效字符
                    if (flag[s[l]] == true && ++chars[s[l]] > 0) {
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return minsize > s.size()? "": s.substr(min_l, minsize);       
    }
};
