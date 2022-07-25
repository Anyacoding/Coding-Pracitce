法一：先序遍历是 中左右——>我们调整顺序成 中右左——>反转就是后序遍历 左右中
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto root = s.top();
            ans.push_back(root->val);
            s.pop();
            if (root->left) s.push(root->left);
            if (root->right) s.push(root->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
