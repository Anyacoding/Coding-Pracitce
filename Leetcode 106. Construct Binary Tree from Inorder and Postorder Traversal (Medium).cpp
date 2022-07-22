法一：其实是一类树构造题目了，相当于板子了

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
    unordered_map<int, int> hash;
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        for (int i = 0; i < n; ++i) {
            hash[in[i]] = i;
        }
        return build(post, 0, n - 1, 0, n - 1);
    }

    TreeNode* build(vector<int>& post, int in_begin, int in_end, int post_begin, int post_end) {
        if (in_begin > in_end || post_begin > post_end) { return nullptr; }
        int index = hash[post[post_end]];
        TreeNode* root = new TreeNode(post[post_end]);
        if (post_begin == post_end) { return root; };
        int rightLen = in_end - index;
        root->left = build(post, in_begin, index - 1, post_begin, post_end - 1 - rightLen);
        root->right = build(post, index + 1, in_end, post_end - rightLen, post_end - 1);
        return root;
    }
};
