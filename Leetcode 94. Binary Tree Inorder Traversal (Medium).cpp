法一：递归的调用过程是不断往左边走，当左边走不下去了，就打印节点，并转向右边，然后右边继续这个过程。
我们在迭代实现时，就可以用栈来模拟上面的调用过程。

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode*> s;
        while (!s.empty() || root != nullptr) {
            if (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            else {
                auto node = s.top();
                s.pop();
                ans.push_back(node->val);
                root = node->right;
            }
        }
        return ans;
    }
};
