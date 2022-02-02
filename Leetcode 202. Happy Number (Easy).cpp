class Solution {
public:
    bool isHappy(int n) {
        string str = to_string(n);
        set<int> check;
        check.insert(n);
        while (n != 1) {
            n = 0;
            for (auto &it : str) {
                n += pow(it - '0', 2);
            }
            if (check.find(n) != check.end()) return false;
            check.insert(n);
            str = to_string(n);
        }
        return true;
    }
};
