法一：二分图算法，利用bfs进行染色，保证相邻的节点颜色不一样，若出现一样的情况则不是二分图

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return true;
        vector<int> color(n, 0);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                color[i] = 1;
                q.push(i);
            }
            while (!q.empty()) {
                auto node = q.front();
                q.pop();
                for (const int j : graph[node]) {
                    if (color[j] == 0) {
                        color[j] = color[node] == 1 ? 2 : 1;
                        q.push(j);
                    }
                    else if (color[j] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
