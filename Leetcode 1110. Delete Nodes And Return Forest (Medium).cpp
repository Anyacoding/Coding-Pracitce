法一：shit，其实写的很不优雅，最后屈服了甚至用一个bool来判断是不是要删除头结点
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
    vector<TreeNode*> ans;
    bool del = true;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> hash(to_delete.begin(), to_delete.end());
        help(nullptr, root, 0, 0, hash);
        if (del) ans.push_back(root);
        return ans;
    }
    void help(TreeNode* father, TreeNode* root, bool left, bool right, unordered_set<int>& hash) {
        if (root == nullptr) return;
        help(root, root->left, 1, 0, hash);
        help(root, root->right, 0, 1, hash);
        if (hash.count(root->val) != 0) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            hash.erase(root->val);
            if (left) father->left = nullptr;
            else if (right) father->right = nullptr;
            else del = false;
        }
    }
};
