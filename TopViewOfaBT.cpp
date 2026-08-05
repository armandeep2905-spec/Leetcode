#include <iostream>
#include <vector>
#include <queue>
# include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildTree() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    TreeNode* root = new TreeNode(x);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}


void topView(TreeNode* root){

    queue<pair<TreeNode* , int >> q;
    map <int , int > m;
    q.push({root , 0});
    while(!q.empty()){
        TreeNode* curr = q.front().first;
        int currDist = q.front().second;
        q.pop();

        if(m.find(currDist) == m.end()){
            m[currDist] = curr->val;
        }

        if(curr ->left != NULL){
            q.push({curr -> left , currDist - 1});
        }
        if(curr -> right != NULL){
            q.push({curr -> right , currDist + 1});
        }

    }
     cout<<"Top View :"<< endl;
    for(auto it : m){
        cout<<it.second<<" ";
    }

}

int main() {
    TreeNode* root = buildTree();
    topView(root);
}