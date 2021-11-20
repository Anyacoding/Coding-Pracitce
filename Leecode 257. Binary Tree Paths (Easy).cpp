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
    void dfs(vector<string>& ans, TreeNode* node, string& path) {
        if (node == nullptr) return;
        int data = node->val;
        char val[25];
        //将int转换为字符，嘤嘤嘤，之前都没有考虑过怎么实现这种细节
        sprintf(val, "%d", data);
         //因为node->val有可能是三位数也可能是两位数或者一位数
         //回溯的时候要重建的位数可能不同
         int count;
         if (data < 0) {
             data = -data;
             //多一个负号，要加上
             if (data >= 0 && data < 10)
             count = 2;
             else if (data >= 10 && data < 99)
             count = 3;
             else 
             count = 4;
         }
         else {
             if (data >= 0 && data < 10)
             count = 1;
             else if (data >= 10 && data < 99)
             count = 2;
             else 
             count = 3;
         }
        if (node->left == nullptr && node->right == nullptr) {
            path += val;
            ans.push_back(path);
            //回溯捏
            path.erase(path.size() - count, count);
            return;
        }
        path += val;
        path += "->";
        dfs(ans, node->left, path);
        dfs(ans, node->right, path);
        path.erase(path.size() - 2 - count, 2 + count);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr) return ans;
        string path;
        dfs(ans, root, path);
        return ans;
    }
};
