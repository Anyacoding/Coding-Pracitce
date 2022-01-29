class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber != 0) {
            char x = (columnNumber - 1) % 26  + 'A';
            ans += x;
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
