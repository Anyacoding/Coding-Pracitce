法一：单纯的BFS写法，全部都是我自己写的，但这样超时了，理论上是可行的
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (edges.size() == 0) return {0};
        vector<vector<int>> Graph(n, vector<int>(n, 0));
        //构建邻接矩阵
        for (int i = 0; i < edges.size(); ++i) {
            Graph[edges[i][0]][edges[i][1]] = 1;
            Graph[edges[i][1]][edges[i][0]] = 1;
        }
        vector<vector<int>> bucket(n + 1); //用来记录树的高度和根节点
        int min_hight = 99999;
        for (int i = 0; i < n; ++i) { //每一个节点都尝试让他们当根节点  
            unordered_set<int> dict;
            for (int j = 0; j < n; ++j) {
                dict.insert(j); //初始化字典，用来存储节点标签
            }
            int target = i; //记录根节点标签
            int hight = 0; //初始高度，其实也是BFS的层数
            queue<int> path;
            path.push(i); //将当前节点当作根节点压入队列
            dict.erase(i);
            while (!path.empty()) {
                ++hight;
                if (dict.empty() == true) {
                    bucket[hight].push_back(target);
                    min_hight = min(min_hight, hight);
                    break;
                }
                int size = path.size();
                for (int s = 1; s <= size; ++s) { //对当前层所有节点进行扩充
                    int node = path.front(); //取出节点
                    path.pop(); //节点出队
                    for (int k = 0; k < n; ++k) {
                        if (k == node) continue; //忽略本身
                        if ((Graph[node][k] == 1 || Graph[k][node] == 1) && dict.count(k) != 0) { //从当前节点到k是有边的，且k没被使用过
                            path.push(k); //更新下一层节点
                            dict.erase(k); //将使用过的结点擦掉
                        }
                        if (dict.empty() == true) break; //所有节点已经使用完了
                    }
                    if (dict.empty() == true) break; //所有节点已经使用完了
                }
            }

        }
        // for (int i = 1; i <= n; ++i) {
        //     if (bucket[i].size() != 0) {
        //         ans = bucket[i];
        //         break;
        //     }
        // }
        ans = bucket[min_hight];
        return ans;
    }
};

法二：BFS的拓扑排序，非常巧妙
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n == 1) return {0};
        if (n == 2) return {0, 1};
        map<int, vector<int>> Graph; //构建邻接表
        vector<int> degree(n); //出度表
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            ++degree[u];
            ++degree[v];
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) { //将所有出度为1的节点都压入队列，也就是叶子节点全部压入队列，从外向里修建
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            ans.clear(); //在还没有得到结果前，这里面存的都是摘下来的叶子节点
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int temp = q.front(); //拿出一个叶子节点
                q.pop(); //出队
                ans.push_back(temp);
                --degree[temp]; //叶子节点被拿出来，就相当于被从树上摘下来了，此时出度为0
                for (auto it : Graph[temp]) { //把与temp原本邻接的节点，且出度为1的节点压入ans中
                    --degree[it]; //因为temp被摘掉了，所以it的出度-1
                    if (degree[it] == 1)
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
