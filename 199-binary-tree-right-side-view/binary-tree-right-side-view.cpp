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
    vector<int> rightSideView(TreeNode* root) {
        // using map 
    //     map < int , int > mp;
    //     vector<int> ans;
    //     if(root == NULL ) return ans; // so we dont push null in the starting 
    //     queue<pair<TreeNode*,int>>q;
    //     q.push({root ,  0}); // initial level = 0
      

    //     while(!q.empty()){
    //         TreeNode* curr = q.front().first;
    //         int currLevel = q.front().second;
    //         q.pop();

    //         if(mp.find(currLevel) == mp.end()) { mp[currLevel] = curr->val; ans.push_back(mp[currLevel]); }
    //         // we go from right to left bcauz of right side view
    //         if(curr->right!= NULL) q.push({curr->right , currLevel + 1}); // level will increase
    //         if(curr->left != NULL) q.push({curr->left , currLevel + 1});  // level will increase 

    //     }

    //  return ans;

     // without using map
      vector<int> ans;
        if(root == NULL ) return ans; // so we dont push null in the starting 
        queue<pair<TreeNode*,int>>q;
        q.push({root ,  0}); // initial level = 0
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int currLevel = q.front().second;
            q.pop();

            if(ans.size() == currLevel)  ans.push_back(curr->val); 
            // we go from right to left bcauz of right side view
            if(curr->right!= NULL) q.push({curr->right , currLevel + 1}); // level will increase
            if(curr->left != NULL) q.push({curr->left , currLevel + 1});  // level will increase 

        }

     return ans;

    }
};