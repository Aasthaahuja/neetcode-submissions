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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightDFS(root, 0, res);
        return res;
    }
    void rightDFS(TreeNode* node, int level, vector<int>& res)
    {
        if(node == nullptr) return;
        if(res.size() == level) res.push_back(node->val);
        rightDFS(node->right, level + 1, res);
        rightDFS(node->left, level + 1, res);
    }
};
