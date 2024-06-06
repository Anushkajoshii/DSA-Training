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
    int height(TreeNode* root,int &max_edges){
        if(root== NULL) return 0;
        int l= height(root->left, max_edges);
        int r= height(root->right, max_edges);
        max_edges= max(max_edges, l+r);
        return 1+ max(l,r);    
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max_edges=0;
        height(root, max_edges);
        return max_edges;
    }
};

//gfg
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root, int &temp){
        if(root ==NULL){
            return 0;
        }
        int l=0, r=0; //height
        int left= height(root->left, l); //diameter
        int right= height(root->right, r);
        temp= 1+max(l,r);
        return max({left, right,(l+r+1)});
    }
    int diameter(Node* root) {
        // Your code here
        int temp=0;
        int ans= height(root, temp);
        return ans;
    }
};