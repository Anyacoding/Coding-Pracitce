法一：这里我用的是我更喜欢的不偏移版本的KMP
class Solution {
public:
    //获得KMP的前缀表，这里采取的是不减1的版本
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = j; 
        for (int i = 1; i < s.size(); ++i) {
            //前缀和后缀不匹配时回退
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                ++j;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                ++j;
            }
            if (j == needle.size()) return i - needle.size() + 1;
        }
        return -1;
    }
};
