class Solution {
public:
    int countValidWords(string sentence) {
        istringstream in(sentence);
        string temp;
        int cnt = 0;
        while (in >> temp) {
            if (IsWord(temp)) {
                ++cnt;
            }
        }
        return cnt;
    }
    bool IsWord(const string &s) {
        int flag = true;
        int num_con = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                flag = false; break;
            }
            if (s[i] >= 'A' && s[i] <= 'Z') {
                flag = false; break;
            }
            if ((i == s.size() - 1 || i == 0) && s[i] == '-') {
                flag = false; break;
            }
            if ((i != s.size() - 1 || i != 0) && s[i] == '-') {
                ++num_con;
                if (num_con > 1) {
                    flag = false; break;
                }
                if (s[i - 1] == '.' || s[i - 1] == '!' || s[i - 1] == ',') {
                    flag = false; break;
                }
                if (s[i + 1] == '.' || s[i + 1] == '!' || s[i + 1] == ',') {
                    flag = false; break;
                }
            }
            if (i != s.size() - 1 && (s[i] == '.' || s[i] == '!' || s[i] == ',')) {
                flag = false; break;
            }
        }
        return flag;
    }
};
