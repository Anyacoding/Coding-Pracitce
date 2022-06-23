法一：中序遍历过程中，记录错误两个错误排序节点，最后进行交换

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
    TreeNode* bad1 = nullptr, * bad2 = nullptr, * pre = nullptr;
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(bad1->val, bad2->val);
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (pre != nullptr && pre->val > root->val) {
            if (bad1 == nullptr) bad1 = pre;
            bad2 = root;
        }
        pre = root;
        dfs(root->right);
    }
};
