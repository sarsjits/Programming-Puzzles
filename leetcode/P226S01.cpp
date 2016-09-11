/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void _invertTree(TreeNode *root) {
        if(root == nullptr) return;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        _invertTree(root->left);
        _invertTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        _invertTree(root);
        return root;
    }
};
