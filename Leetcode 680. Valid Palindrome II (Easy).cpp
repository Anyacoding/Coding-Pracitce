class Solution {
public:
    bool validPalindrome(string s) {
        //小于3的一定可以变成回文
        if (s.size() < 3)
        return true;
        //一次修改机会
        bool round1 = true;
        bool round2 = true;
        for (int i = 0, j = s.size() - 1; i <= j;) {
            if (s[i] != s[j]) {
                //可以修改一次
                //进行回合一
                if (s[j - 1] == s[i]) {
                    for (int l = i, r = j - 1; l <= r; l++, r--) {
                        if (s[r] != s[l]) {
                            round1 = false;
                            break;
                        }
                    }
                    if (round1 == true) {
                        return true;
                    }
                }
                //进行回合二
                if (s[i + 1] == s[j]) {
                   for (int l = i + 1, r = j; l <= r; l++, r--) {
                        if (s[r] != s[l]) {
                            round2 = false;
                            break;
                        }
                    }
                    if (round2 == true) {
                        return true;
                    }
                }
                return false;     
            }

            else {
                ++i;
                --j;
            }
        }
        return true;
    }
};

