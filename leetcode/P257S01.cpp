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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr) return ans;
        if(root->left == nullptr && root->right == nullptr) {
            ans.push_back(to_string(root->val));
            return ans;
        }
        string intermediary = to_string(root->val) + "->";
        for(auto str : binaryTreePaths(root->left)) {
            ans.push_back(intermediary + str);
        }
        for(auto str : binaryTreePaths(root->right)) {
            ans.push_back(intermediary + str);
        }
        return ans;
    }
};
