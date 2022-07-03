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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return nullptr;
        TreeNode* ans = new TreeNode();
        if (root1) {
            ans->val += root1->val;
        }
        if (root2) {
            ans->val += root2->val;
        }
        ans->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        ans->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
        return ans;
    }
};
