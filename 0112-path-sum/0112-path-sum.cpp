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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int sum = 0;
        // sum += root->val;

        return solve(root, targetSum,sum);
    }

    bool solve(TreeNode* root, int& targetSum, int sum){
        if(root == NULL) return false;

        sum += root->val;
        
        if(root->left == NULL && root->right == NULL){
            if(targetSum == sum) return true;
            return false;
        }
        
        int lh = solve(root->left, targetSum, sum);
        // sum -= root->val;
        int rh =  solve(root->right, targetSum, sum);

        return lh || rh;
    }
};