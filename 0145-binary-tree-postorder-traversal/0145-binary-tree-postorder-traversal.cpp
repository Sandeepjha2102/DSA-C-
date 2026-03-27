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

    void postorderfn(vector<int>& postorder, TreeNode* root){
        if(root == NULL) return;
        postorderfn(postorder, root->left);
        postorderfn(postorder, root->right);
        postorder.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        postorderfn(postorder, root);
        return postorder;
    }
};