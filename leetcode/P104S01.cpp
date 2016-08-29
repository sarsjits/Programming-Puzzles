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
    int solve(TreeNode *root, int depth) {
        if(root == nullptr)
            return depth;
        return max(solve(root->left,depth+1),solve(root->right,depth+1));
    }
    int maxDepth(TreeNode* root) {
        return solve(root,0);
    }
};
