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
    TreeNode* helper ( vector<int> pre ,  vector<int> in , int &preIndex , int in_start , int in_end){
       if(in_start > in_end) return NULL;
        int in_idx = in_start;
        TreeNode* newRoot = new TreeNode(pre[preIndex]);
        preIndex++;
        while(true){ // to find corresponding in order index 
             if(newRoot->val == in[in_idx]){
                break;
             }
             in_idx++;
        }
        newRoot->left = helper(pre , in ,  preIndex , in_start , in_idx - 1); // from inorder index we know the start and end of left and right subtree of curr tree
        newRoot->right = helper(pre , in ,  preIndex , in_idx+1 , in_end);
        return newRoot;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex = 0;
       return helper(preorder , inorder , preindex , 0 , preorder.size()-1);

    }
};