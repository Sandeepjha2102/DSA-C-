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
    
    int findHeight(TreeNode* root, int& parent, int value, int height){
        if(root == NULL) return -1;  

        if(root->val == value) return height;

        // check left subtree
        int leftParent = root->val;
        int left = findHeight(root->left, leftParent, value, height+1);
        if(left != -1){              
            parent = leftParent;
            return left;
        }

        // check right subtree
        int rightParent = root->val;
        int right = findHeight(root->right, rightParent, value, height+1);
        if(right != -1){            
            parent = rightParent;
            return right;
        }

        return -1;                 
    }


    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y) return false;

        int xparent = -1;
        int xHeight = findHeight(root, xparent, x, 0);

        int yparent = -1;
        int yHeight = findHeight(root, yparent, y, 0);

        if(xparent != yparent && xHeight == yHeight) return true;
        return false;
    }
};