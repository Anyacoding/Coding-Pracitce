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
    unordered_set<int> hash;
    bool findTarget(TreeNode* root, int k) {
        help(root);
        //if (hash.size() == 1 && *hash.begin() != k) return false;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            if (hash.count(k - *it) != 0 && hash.find(k - *it) != it) return true;
        }
        return false;
    }

    void help(TreeNode* root) {
        if (root == nullptr) return;
        help(root->left);
        hash.insert(root->val);
        help(root->right);
    }
};
