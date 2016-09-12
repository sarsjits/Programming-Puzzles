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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode *> Q;
        Q.push(root);
        while(1) {
            int lengthOfLevel = Q.size();
            if(lengthOfLevel == 0) {
                reverse(ans.begin(),ans.end());
                return ans;
            }
            vector<int> curLevel;
            while(lengthOfLevel > 0) {
                TreeNode *curNode = Q.front();
                curLevel.push_back(curNode->val);
                Q.pop();
                if(curNode->left != nullptr) Q.push(curNode->left);
                if(curNode->right != nullptr) Q.push(curNode->right);
                lengthOfLevel--;
            }
            ans.push_back(curLevel);
        }
    }
};
