法一：中心扩散法，求回文子串的很妙的一种做法
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int len = 1;
        int maxlen = 0;
        int maxleft = 0;
        for (int mid = 0; mid < s.size(); ++mid) {
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && s[left] == s[mid]) {
                --left;
                ++len;
            }
            while (right < s.size() && s[right] == s[mid]) {
                ++right;
                ++len;
            }
            while (left >= 0 && right < s.size() && s[right] == s[left]) {
                --left;
                ++right;
                len += 2;
            }
            if (len > maxlen) {
                maxlen = len;
                maxleft = left + 1;
            }
            len = 1;
        }
        return s.substr(maxleft, maxlen);
    }
};
