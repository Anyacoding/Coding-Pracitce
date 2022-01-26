法一：
对于下标为 0 位置，从 [0, n - 1] 随机一个位置进行交换，共有 n 种选择；
下标为 1 的位置，从 [1, n - 1] 随机一个位置进行交换，共有 n - 1 种选择 ...  这样洗牌就是等可能的了

class Solution {
public:
    vector<int> origin;
    Solution(vector<int>& nums): origin(nums) {}

    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int> shuffle(origin);
        int n = shuffle.size();
        //可以正向洗牌也可以反向洗牌
        //正向洗牌
        for (int i = 0; i < n; ++i) {
            int pos = rand() % (n - i);
            swap(shuffle[i], shuffle[i + pos]);
        }
        //反向洗牌
        // for (int i = n - 1; i >= 0; --i) {
        //     swap(shuffle[i], rand() % (i + 1));
        // }
        return shuffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
