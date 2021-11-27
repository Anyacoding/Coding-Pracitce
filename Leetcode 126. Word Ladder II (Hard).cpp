法一：DFS和BFS结合使用，这个方法有些细节我不能理解，日后再看
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> res;
        // 因为需要快速判断扩展出的单词是否在 wordList 里，因此需要将 wordList 存入哈希表，这里命名为「字典」
        unordered_set<string> dict = {wordList.begin(), wordList.end()};
        // 修改以后看一下，如果根本就不在 dict 里面，跳过
        if (dict.find(endWord) == dict.end()) {
            return res;
        }
        // 特殊用例处理
        dict.erase(beginWord);

        // 第 1 步：广度优先遍历建图
        // 记录扩展出的单词是在第几次扩展的时候得到的，key：单词，value：在广度优先遍历的第几层
        unordered_map<string, int> steps = {{beginWord, 0}};
        // 记录了单词是从哪些单词扩展而来，key：单词，value：单词列表，这些单词可以变换到 key ，它们是一对多关系
        unordered_map<string, set<string>> from = {{beginWord, {}}};
        int step = 0;
        bool found = false;
        queue<string> q = queue<string>{{beginWord}};
        int wordLen = beginWord.length();
        while (!q.empty()) {
            step++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                const string currWord = move(q.front());
                string nextWord = currWord;
                q.pop();
                // 将每一位替换成 26 个小写英文字母
                for (int j = 0; j < wordLen; ++j) {
                    const char origin = nextWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        //这一步是用来干啥的，意义不明
                        if (steps[nextWord] == step) {
                            from[nextWord].insert(currWord);
                        }
                        //拓展出来的词不在词典里，直接跳过本次循环
                        if (dict.find(nextWord) == dict.end()) {
                            continue;
                        }
                        // 如果从一个单词扩展出来的单词以前遍历过，距离一定更远，为了避免搜索到已经遍历到，且距离更远的单词，需要将它从 dict 中删除
                        dict.erase(nextWord);
                        // 这一层扩展出的单词进入队列
                        q.push(nextWord);
                        // 记录 nextWord 从 currWord 而来
                        from[nextWord].insert(currWord);
                        // 记录 nextWord 的 step
                        steps[nextWord] = step;
                        if (nextWord == endWord) {
                            found = true;
                        }
                    }
                    nextWord[j] = origin;
                }
            }
            if (found) {
                break;
            }
        }
        // 第 2 步：深度优先遍历找到所有解，从 endWord 恢复到 beginWord ，所以每次尝试操作 path 列表的头部
        if (found) {
            vector<string> Path = {endWord};
            dfs(res, endWord, from, Path);
        }
        return res;
    }

    void dfs(vector<vector<string>> &res, const string &Node, unordered_map<string, set<string>> &from,
             vector<string> &path) {
        if (from[Node].empty()) {
            res.push_back({path.rbegin(), path.rend()});
            return;
        }
        for (const string &Parent: from[Node]) {
            path.push_back(Parent);
            dfs(res, Parent, from, path);
            path.pop_back();
        }
    }
};

法二：这种方法是纯BFS，我比较能接受的是这种，而且我也完成了一遍复现，并且我也破解了一个误区，就是BFS也能完成回溯，回溯并不是DFS的专利
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end()); //一个字典树，是用来判断变化后得到的字符是否在wordList里面
        dict.erase(beginWord); //以防万一还是把beginWord擦掉
        queue<vector<string>> work; //队列层结点容器，并同时放入beginword
        work.push({ beginWord });
        while (!work.empty()) {
            unordered_set<string> visited; //记录一层内已经转换过的string，用set可以避免重复保存
            int size = work.size(); //这里之前出现了一个死循环，之前的判断条件为for (int i = 1; i <= work.size(); ++i)，但由于后续操作会改变work.size()的值
            //所以会进入死循环，这里一开始就把size固定下来是好的，意为当前层的节点个数
            for (int i = 1; i <= size; ++i) {
                auto path = work.front(); //取得当前层的第一个结点，每个结点其实就是一条路径,类型是vector<string>
                work.pop();//出队操作
                auto tail = path.back(); //取得当前path的最后一个string
                if (tail == endWord) {
                    ans.push_back(path); //当前path能够转换成endWord，即可压入ans数组
                    continue; //直接对当前层的其他结点进行检查，可能有别的path也能转换成endWord
                }
                //以下是当前结点不能转换成endWord的情况，则对tail进行变形拓展，形成下一层的结点path
                for (int j = 0; j < tail.size(); ++j) {
                    const char orign = tail[j]; //保存tail要变形的字符，方便最后回溯
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orign) continue; //忽略本身
                        tail[j] = c;
                        if (dict.count(tail) != 0) {  //转换字符串在字典中可以找到
                            path.push_back(tail); //将转换后的字符压入path里，形成新的path也就是下一层的新节点
                            work.push(path); //更新下一层节点
                            path.pop_back(); //回溯，恢复成当前节点
                            visited.insert(tail); //记录当前层已经转换过的字符串
                            
                            //dict.erase(tail);这里不直接在dict里把转换得到的tail删除是因为在同一层中
                            //别的节点路径也是有可能需要用到当前转换得到的tail的，我们需要保证的是单条路径不同层中不能有相同的字符串
                            //但是多条路径中同层可以有相同的字符串例如
                            //"hit" -> "hot" -> "dot" -> "dog" -> "cog"
                            //"hit" -> "hot" -> "lot" -> "log" -> "cog"  两条路径中第一层都是hot，这是允许的
                        }
                    }
                    tail[j] = orign;//回溯，恢复成初始状态并进行下一位的变形
                }
            }
            if (ans.size() != 0) return ans; //第一次到达树底，也就是得到最小转换序，path的长度其实就是层数，每一层中的path长度都是一样的
                                             //所以率先能够被压入ans的path就是最短路径
            for (auto &it : visited) dict.erase(it); //当前层用过的转换字符串全部擦掉,这样就可以保证下一层不会使用前面层已经用过的字符串
        }
        return {};
    }
};
