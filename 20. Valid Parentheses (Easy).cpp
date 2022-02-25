法一：经典做法就是用栈来处理
class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                check.push(s[i]);
            }
            else if (s[i] == ')') {
                if (check.empty() || check.top() != '(') return false;
                check.pop();
            }
            else if (s[i] == ']') {
                if (check.empty() || check.top() != '[') return false;
                check.pop();
            }
            else if (s[i] == '}') {
                if (check.empty() || check.top() != '{') return false;
                check.pop();
            }
        }
        if (!check.empty()) return false;
        return true;
    }
};
