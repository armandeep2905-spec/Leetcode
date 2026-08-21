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
   priority_queue<int> q;
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return q.top();
        q.push(root->val);
        while(q.size() > k ) q.pop();
        if(root->left!= NULL) kthSmallest(root->left ,  k);
        if(root->right != NULL) kthSmallest( root->right, k);

        return q.top();
    }
};