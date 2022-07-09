
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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        help(root);
        return sum;
    }

    void help(TreeNode* root) {
        if (root == nullptr) return;
        sum += root->left && root->left->left == nullptr && root->left->right == nullptr ? root->left->val : 0;
        help(root->left);
        help(root->right);
    }
};
