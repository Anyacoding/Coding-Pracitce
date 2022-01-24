class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string ans;
        int add = 0;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0? num1[i] - '0' : 0;
            int y = j >= 0? num2[j] - '0' : 0;
            int res = x + y + add;
            ans.push_back('0' + res % 10);
            add = res / 10;
            --i;
            --j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
