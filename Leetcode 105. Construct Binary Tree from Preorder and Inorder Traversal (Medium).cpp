法一：经典题目

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        unordered_map<int, int> hash;
        for (int i = 0; i < inorder.size(); ++i) {
            hash[inorder[i]] = i;
        }
        return build(hash, preorder, 0, preorder.size() - 1, 0);
    }
    TreeNode* build(unordered_map<int, int>& hash, vector<int>& preorder, int begin, int end, int i) {
        if (begin > end) return nullptr;
        int mid = preorder[i]; 
        int index = hash[mid];
        int leftLen = index - begin;
        TreeNode* node = new TreeNode(mid);
        node->left = build(hash, preorder, begin, index - 1, i + 1);
        node->right = build(hash, preorder, index + 1, end, i + 1 + leftLen);
        return node;
    }
};
