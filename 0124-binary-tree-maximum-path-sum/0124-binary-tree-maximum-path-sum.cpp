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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        finder(root, maxSum);
        return maxSum;
    }
    int finder(TreeNode* root, int& maxSum){
        if(root == NULL) return 0;

        int lh = max(0, finder(root->left, maxSum));
        int rh = max(0, finder(root->right, maxSum));

        maxSum = max(maxSum, root->val+lh+rh);

        return root->val + max(lh, rh);
    }
};