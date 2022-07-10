法一：BST的中序遍历就是从小到大,那么反过来就是从大到小,然后累加就好了.
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
    int num = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        convertBST(root->right);
        root->val += num;
        num = root->val;
        convertBST(root->left);
        return root;
    }

};
