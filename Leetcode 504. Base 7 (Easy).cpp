法一：简单的进制转换
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string ans;
        stack<int> s;
        if (num < 0) {
            ans += '-';
        }
        while (num != 0) {
            s.push(num % 7);
            num = num / 7;
        }
        while (!s.empty()) {
            int temp = s.top();
            ans += to_string(abs(temp));
            s.pop();
        }
        return ans;
    }
};
