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
    bool _solve(TreeNode *root, int sum) {
        if(root == nullptr) {
            return sum == 0;
        } else {
            bool ans = false;
            int subSum = sum - root->val;
            if(subSum == 0 && root->left == nullptr && root->right == nullptr) return true;
            if(root->left != nullptr)
                ans = ans or _solve(root->left,subSum);
            if(root->right != nullptr)
                ans = ans or _solve(root->right,subSum);
            return ans;
        }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return false;
        else {
            return _solve(root,sum);
        }
    }
};
