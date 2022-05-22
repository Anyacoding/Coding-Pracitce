法一：找递归点
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
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
    bool check(TreeNode* p, TreeNode* q) {
        //两个都是空指针也是对称的
        if (p == nullptr && q == nullptr) return true;
        //若两个结点其中一个是空结点另一个不是，则不对称
        if (p == nullptr || q == nullptr) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
};
