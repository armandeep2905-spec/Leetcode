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

    TreeNode* helper(vector<int> inorder ,  vector<int> postorder , int &idx , int start , int end){
        if(start > end) return NULL;
        TreeNode* newRoot = new TreeNode(postorder[idx]);
        idx++;
        int in_idx = start;
        while(newRoot->val != inorder[in_idx] && start <= end){
            in_idx++;

        }
        newRoot->right = helper(inorder , postorder  , idx , in_idx+1 , end);
        newRoot->left = helper(inorder , postorder , idx , start , in_idx-1);
        return newRoot;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin() , postorder.end());
        int postIdx = 0;
        return helper(inorder , postorder , postIdx , 0 , inorder.size() - 1);
    }
};