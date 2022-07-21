法一：其实是套路题，只是根据前序后序无法确定唯一的树而已，因为无法判断左右儿子

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int len = 0;
    unordered_map<int, int> hash;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        len = pre.size();
        for (int i = 0; i < post.size(); ++i) {
            hash[post[i]] = i;
        }
        return build(pre, 0, pre.size() - 1, 0, post.size() - 1);
    }
    TreeNode* build(vector<int>& pre, int pre_begin, int pre_end, int post_begin, int post_end) {
        if (pre_begin > pre_end || post_begin > post_end) { return nullptr; }
        TreeNode* root = new TreeNode(pre[pre_begin]);
        if (pre_begin == pre_end) { return root; }
        // 错在这里，为什么是找 pre_begin + 1 ？
        int index = hash[pre[pre_begin + 1]]; 
        root->left = build(pre, pre_begin + 1, pre_begin + 1 + index - post_begin, post_begin, index);
        root->right = build(pre, pre_begin + 2 + index - post_begin, pre_end, index + 1, post_end - 1);
        return root;
    }
};
