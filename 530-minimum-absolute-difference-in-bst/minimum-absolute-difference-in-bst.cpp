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
// soln 1 ->
    // vector<int> ans;
    // vector<int> inorder(TreeNode* root){
    //     if(root == NULL) return ans;
    //     inorder(root->left);
    //     ans.push_back(root->val);
    //     inorder(root->right);
    //     return ans;
    // }
    // int getMinimumDifference(TreeNode* root) {
     
   
    //     int ans = 0;
    //     vector<int> order;
    //  // finding the sorted order
    //    order = inorder(root); 
    //    int minDis = INT_MAX;
    //    for(int i = 1 ; i < order.size() ; i++){
    //         minDis = min(minDis , order[i] - order[i-1] );
    //    }
    // return minDis;

//soln 2->

    TreeNode* prev = NULL;
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return ans;
        if(root -> left !=NULL) getMinimumDifference(root->left);
        if(prev != NULL)  ans = min (ans , root->val - prev->val);
        prev = root ;
        if(root -> right !=NULL)  getMinimumDifference(root->right);
        return ans;
    }
};