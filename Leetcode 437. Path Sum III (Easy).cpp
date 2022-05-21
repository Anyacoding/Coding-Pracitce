法一：树的遍历 + DFS
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
    using ll = long long;
    ll ans = 0;
    ll target = 0;
    int pathSum(TreeNode* root, ll targetSum) {
        this->target = targetSum;
        dfs1(root);
        return ans;
    }
    void dfs1(TreeNode* root) {
        if (root == nullptr) return;
        dfs2(root, root->val);
        dfs1(root->left);
        dfs1(root->right);
    }
    void dfs2(TreeNode* root, ll sum) {
        if (sum == target) ++ans;
        if (root->left) dfs2(root->left, sum + root->left->val);
        if (root->right) dfs2(root->right, sum + root->right->val);
    }
};
