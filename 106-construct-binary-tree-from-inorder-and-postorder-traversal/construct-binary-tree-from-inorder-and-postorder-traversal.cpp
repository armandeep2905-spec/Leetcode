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
 // reversed postorder ->   root -> right -> left 

    TreeNode* helper(vector<int> inorder ,  vector<int> postorder , int &idx , int start , int end){
        if(start > end) return NULL;
        TreeNode* newRoot = new TreeNode(postorder[idx]); // built root 
        idx++;
        int in_idx = start;
        while(newRoot->val != inorder[in_idx] && start <= end){ // extra condition for getting inorder index out of bound
            in_idx++;

        }
        newRoot->right = helper(inorder , postorder  , idx , in_idx+1 , end); // built right
        newRoot->left = helper(inorder , postorder , idx , start , in_idx-1); // built left
        return newRoot;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin() , postorder.end());
        int postIdx = 0;
        return helper(inorder , postorder , postIdx , 0 , inorder.size() - 1);
    }
};