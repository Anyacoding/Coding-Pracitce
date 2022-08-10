法一：并查集通用实现，板子题

class UF {
    vector<int> father;
public:
    UF(int n): father(n) {
        iota(father.begin(), father.end(), 0);
    }
    int find(int p) {
        while (p != father[p]) {
            p = father[p];
        }
        return p;
    }
    void connecte(int p, int q) {
        father[find(p)] = find(q);
    }
    bool is_connected(int p, int q) {
        return find(p) == find(q);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF set(n + 1);
        for (const auto e : edges) {
            auto p = e[0];
            auto q = e[1];
            if (set.is_connected(p, q) == true) {
                return e;
            }
            set.connecte(p, q);
        }
        return {-1, -1};
    }
};
