法一：分治法
利用分治思想，我们可以把加括号转化为，对于每个运算符号，先执行处理两侧的数学表达
式，再处理此运算符号。注意边界情况，即字符串内无运算符号，只有数字。
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1, expression.size() + 1));
                for (const auto &l : left) {
                    for (const auto &r : right) {
                        switch(c)
                        {
                            case '+': ans.push_back(l + r); break;
                            case '-': ans.push_back(l - r); break;
                            case '*': ans.push_back(l * r); break;
                        }
                    }
                }
            }
        }
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};
