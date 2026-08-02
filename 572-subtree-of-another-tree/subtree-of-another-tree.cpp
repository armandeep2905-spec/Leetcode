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
    bool checkTree(TreeNode* curr ,TreeNode* subRoot){
       if(curr == NULL && subRoot == NULL) return true;
       if(curr == NULL || subRoot == NULL) return false;
       if(curr->val != subRoot->val) return false;
       return checkTree(curr->left , subRoot->left) && checkTree(curr->right , subRoot->right);
    } 

    bool isSame(TreeNode* root , TreeNode* subRoot){
        if(root == NULL) return false;
           if(root->val == subRoot->val) {
              if(checkTree(root , subRoot)) return true;
           }
           return isSame(root->left , subRoot) || isSame(root->right , subRoot);
    }
           
           

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         return isSame(root , subRoot);
    }
};