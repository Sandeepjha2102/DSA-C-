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

    void inorderfn(vector<int>& inorder, TreeNode* root){
        if(root == NULL) return;
        inorderfn(inorder, root->left);
        inorder.push_back(root->val);
        inorderfn(inorder, root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inorderfn(inorder, root);
        return inorder;
    }
};