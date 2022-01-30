class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int add = 0;
        int temp = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0? a[i] - '0' : 0;
            int y = j >= 0? b[j] - '0' : 0;
            int temp = (x + y + add) % 2;
            ans += to_string(temp);
            add = (x + y + add) / 2;
            --i;
            --j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
