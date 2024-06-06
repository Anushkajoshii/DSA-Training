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
class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=false;
        stack<int> s;
        while(!q.empty()){
            int n =q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode * curr= q.front();
                q.pop();
                if(leftToRight){
                    s.push(curr->val);
                }
                else{
                    temp.push_back(curr->val);
                }
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
                while(!s.empty()){
                    temp.push_back(s.top());
                    s.pop();   
                }  
            ans.push_back(temp);
            leftToRight=!leftToRight;
        }
        return ans;
    }  
};