法一：拓扑排序，建立邻接表即可

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (const auto& node : prerequisites) {
            graph[node[1]].push_back(node[0]);
            //cout << node[1] << " " << node[0] << endl;
            ++indegree[node[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto id = q.front();
            q.pop();
            ans.push_back(id);
            for (int i = 0; i < graph[id].size(); ++i) {
                --indegree[graph[id][i]];
                if (indegree[graph[id][i]] == 0) {
                    q.push(graph[id][i]);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};
