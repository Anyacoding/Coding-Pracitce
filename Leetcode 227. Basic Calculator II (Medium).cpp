//两个栈，一个符号栈一个数字栈
class Solution {
public:
    using ll = long long;
    stack<ll> num;
    stack<char> op;
    int calculate(string s) {
        s = '0' + s;
        unordered_map<char, int> level;
        level['+'] = 1;
        level['-'] = 1;
        level['*'] = 2;
        level['/'] = 2;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == ' ') continue;
            if (isdigit(c)) {
                ll result = 0, j = i;
                while (j < s.size() && isdigit(s[j])) {
                    result = result * 10 + s[j] - '0';
                    ++j;
                }
                num.push(result);
                i = j - 1;
            }
            else {
                while (op.size() && level[op.top()] >= level[c]) eval();
                op.push(c);
            }
        }
        while (op.size()) eval();
        return num.top();
    }
    void eval() {
        ll a = num.top(); num.pop();
        ll b = num.top(); num.pop();
        switch(op.top()) {
            case '+': 
            num.push(a + b); break;
            case '-':
            num.push(b - a); break;
            case '*':
            num.push(a * b); break;
            case '/':
            num.push(b / a); break;
        };
        op.pop();
        return;
    }
};
