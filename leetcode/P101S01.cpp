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
    bool isMirrorImage(TreeNode *a, TreeNode *b) {
        if(a == nullptr && b == nullptr) return true;
        if(a == nullptr || b == nullptr) return false;
        return (a->val == b->val) && (isMirrorImage(a->left,b->right)) && (isMirrorImage(a->right,b->left));
    }
    bool isSymmetric(TreeNode* root) {
        return isMirrorImage(root,root);
    }
};
