法一：暴力法，最容易想到的方法，能过一部分点
class Solution {
public:
    string nearestPalindromic(string n) {
        long long size = stoi(n);
        long long base = stoi(n);
        set<int> ans;
        for (int i = 1; i < size && ans.empty(); ++i) {
            long long temp = base - i;
            //cout << temp << " ";
            if (check(to_string(temp))) ans.insert(temp);
            temp = base + i;
            //cout << temp << " ";
            if (check(to_string(temp))) ans.insert(temp);
        }
        return to_string(*ans.begin());
    }
    bool check(const string s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};
法二：
分类讨论
对于任意一个数，如12345，其最近的回文数只会从以下五种中得到：
1.将前一半填入后一半：12321
2.将前一半加一填入后一半：12421
3.将前一半减一填入后一半：12221
4.下边界：9999
5.上边界：100001
从这五个数里面选取不等于原数的，且与原数差距最小的最小的数即为答案。
class Solution {
public:
    string nearestPalindromic(string n) {
        map<long, long> ans;
        long r = 1;
        long l = n.size();
        long mid = (l + r) >> 1;
        long base = stol(n.substr(0, mid));
        long len = n.size();
        //num1 = base，num2 = base+1，num3 = base-1
        string num1, num2, num3;
        string temp;
        //n是奇数的情况
        if (len % 2 != 0) {
            num2 = to_string(base + 1);
            temp = num2.substr(0, num2.size() - 1);
            reverse(temp.begin(), temp.end());
            ans[abs(stol(num2 + temp) - stol(n))] = stol(num2 + temp);
            //ans.insert(stoi(num2 + temp));

            //当n本身不是回文数时才考虑num1
            if (!check(n)) {
                num1 = to_string(base);
                temp = num1.substr(0, num1.size() - 1);
                reverse(temp.begin(), temp.end());
                ans[abs(stol(num1 + temp) - stol(n))] = stol(num1 + temp);
                //ans.insert(stoi(num1 + temp));
            }

            num3 = to_string(base - 1);
            temp = num3.substr(0, num3.size() - 1);
            reverse(temp.begin(), temp.end());
            ans[abs(stol(num3 + temp) - stol(n))] = stol(num3 + temp);
            //ans.insert(stoi(num3 + temp));
        }
        //n是偶数的情况
        else {
            num2 = to_string(base + 1);
            temp = num2.substr(0, num2.size());
            reverse(temp.begin(), temp.end());
            ans[abs(stol(num2 + temp) - stol(n))] = stol(num2 + temp);
            //ans.insert(stoi(num2 + temp));

            //当n本身不是回文数时才考虑num1
            if (!check(n)) {
                num1 = to_string(base);
                temp = num1.substr(0, num1.size());
                reverse(temp.begin(), temp.end());
                ans[abs(stol(num1 + temp) - stol(n))] = stol(num1 + temp);
                cout << num1 + temp;
                //ans.insert(stoi(num1 + temp));
            }

            num3 = to_string(base - 1);
            temp = num3.substr(0, num3.size());
            reverse(temp.begin(), temp.end());
            ans[abs(stol(num3 + temp) - stol(n))] = stol(num3 + temp);
            //ans.insert(stoi(num3 + temp));
        }
        long upper = (long)pow(10, n.size()) + 1;
        long lower = (long)pow(10, n.size() - 1) - 1;
        if (abs(upper - stol(n)) != 0)
        ans[abs(upper - stol(n))] = upper;
        if (abs(lower - stol(n)) != 0)
        ans[abs(lower - stol(n))] = lower;
        return to_string((*ans.begin()).second);
    }
    bool check(const string s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i <= j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};
