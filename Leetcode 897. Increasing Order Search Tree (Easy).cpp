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
    TreeNode* head;
    TreeNode* increasingBST(TreeNode* root) {
        head = nullptr;
        help(root);
        return head;
    }
    void help(TreeNode* root) {
        if (root == nullptr) return;
        help(root->right);
        TreeNode* temp = new TreeNode();
        temp->val = root->val;
        temp->right = head;
        head = temp;
        help(root->left);
    }
};
