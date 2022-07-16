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
    int pre = -999999;
    int cur = -999999;
    int MIN = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        help(root);
        return MIN;
    }
    void help(TreeNode* root) {
        if (root == nullptr) return;
        help(root->left);
        pre = cur;
        cur = root->val;
        MIN = min(MIN, cur - pre);
        cout << MIN << " ";
        help(root->right);
    }
};
