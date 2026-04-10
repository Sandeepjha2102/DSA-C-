/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {

        // If tree is empty, return an empty string
        if (!root) {
            return "";
        }

        // Initialize string to store serialized result
        string s = "";

        // Initialize a queue to store nodes during level-order traversal
        queue<TreeNode*> q;

        // Push root node into the queue
        q.push(root);

        // Loop while queue is not empty
        while (!q.empty()) {

            // Get the current node from the front of the queue
            TreeNode* curNode = q.front();
            q.pop();

            // If current node is null, append "#" to string
            if (curNode == nullptr) {
                s += "#,";
            } 
            else {
                // Append node value to string
                s += to_string(curNode->val) + ",";

                // Push left child into queue
                q.push(curNode->left);

                // Push right child into queue
                q.push(curNode->right);
            }
        }

        // Return the serialized tree string
        return s;
    }

    // Function to deserialize a string and reconstruct the binary tree
    TreeNode* deserialize(string data) {

        // If data is empty, return null
        if (data.empty()) {
            return nullptr;
        }

        // Use stringstream to parse the input data
        stringstream s(data);
        string str;

        // Read the root value from the stream
        getline(s, str, ',');

        // Create the root node
        TreeNode* root = new TreeNode(stoi(str));

        // Initialize a queue to hold tree nodes for level-order reconstruction
        queue<TreeNode*> q;

        // Push root node into the queue
        q.push(root);

        // Loop through the stream to construct the tree
        while (!q.empty()) {

            // Get the current node from the front of the queue
            TreeNode* node = q.front();
            q.pop();

            // Read the left child value
            getline(s, str, ',');

            // If value is not "#", create left node and attach to current node
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read the right child value
            getline(s, str, ',');

            // If value is not "#", create right node and attach to current node
            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        // Return the root of the reconstructed tree
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));