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
    map < int , int > mp;
    void Helper(TreeNode* root , vector<int> &ans ){
        if(root == NULL ) return; // so we dont push null in the starting 
        queue<pair<TreeNode*,int>>q;
        q.push({root ,  0}); // initial level = 0
      

        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int currLevel = q.front().second;
            q.pop();

            if(mp.find(currLevel) == mp.end())  mp[currLevel] = curr->val;
            
            if(curr->right!= NULL) q.push({curr->right , currLevel + 1});
            if(curr->left != NULL) q.push({curr->left , currLevel + 1});

        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        Helper ( root , ans);
        for ( auto it : mp) ans.push_back(it.second);
        return ans;


    }
};