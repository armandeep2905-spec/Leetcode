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


    TreeNode* helper(  vector<int> & pre , int &index , int ub){
        if( index >= pre.size() ) return NULL;
        if(pre[index] > ub) return NULL; 
        TreeNode* root = new TreeNode(pre[index]);
        index++;
       root->left =  helper( pre , index , root->val);
       root->right = helper( pre , index , ub);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ub = INT_MAX;
        int index = 0;
        
  

        return helper ( preorder ,index ,  ub);

    }
};