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
    int depth(TreeNode *root,int d) {
        if(root == nullptr)
            return d;
        return max(depth(root->left,d+1),depth(root->right,d+1));
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        return abs(depth(root->left,0) - depth(root->right,0)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
