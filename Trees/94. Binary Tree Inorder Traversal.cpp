//leetcode
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*>s;
        while(root != nullptr || !s.empty()){
            while(root!=nullptr){
                s.push(root);
                root=root->left;
            }
            root= s.top();
            s.pop();
            res.push_back(root->val);
            root= root->right;
        }
        return res;
    }
};

//gfg
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        stack<Node*> s;
        vector<int> ans;
        while(root!= nullptr || !s.empty()){
            while(root!=nullptr){
                s.push(root);
                root= root->left;
            }
            root=s.top();
            s.pop();
            ans.push_back(root->data);
            root= root->right;
        }
        return ans;
        
    }
};