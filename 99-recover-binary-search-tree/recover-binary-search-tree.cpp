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

// Solution 1 ->
// TreeNode* temp1  = NULL; 
// TreeNode* temp2 = NULL ;
    // vector<TreeNode*> inorder(TreeNode* root ,  vector <TreeNode*> &ans){
    //       if(root == NULL) return ans;
    //       inorder(root->left , ans);
    //       ans.push_back(root);
    //       inorder(root->right , ans);
    //       return ans;
    // }
    // void recoverTree(TreeNode* root) {
        //  vector<TreeNode*> ans;
        //  inorder (root ,  ans);
        // for(int i = 1 ; i < ans.size() ; i++) {
        //     if(ans[i]->val < ans[i-1]->val) {
        //      if(temp1 == NULL){
        //         temp1 = ans[i - 1];
        //     }
        //         temp2 = ans[i];
               
            
        //     }
            
           
        // }
        // swap(temp1->val , temp2->val);



      
       // Solution 2 ->
TreeNode* prev = NULL;
TreeNode* first =  NULL ;
TreeNode* second = NULL;
void inorder(TreeNode* root ){
    if(root == NULL) return; 
    inorder(root->left  );
    if(prev != NULL && root->val < prev->val ){ 
        if (first == NULL ) first = prev;
    second = root;
    }
    prev = root;
    inorder(root->right );

}

void recoverTree(TreeNode* root) {
    inorder ( root );
     swap(first->val , second->val);

    }

};