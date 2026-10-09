/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s = "";
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) s.append("#,");
            else s.append(to_string(temp->val)+ ',');

            if(temp!= NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       // string data -> contains the tree data + #
       if(data.empty()) return NULL;
        stringstream ss(data);
        string ans ;
        getline(ss ,  ans , ',');
        TreeNode* root = new TreeNode(stoi(ans));
        queue<TreeNode*> q ;
        
        q.push(root);
 
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            getline(ss , ans, ',');
            if(ans == "#") temp->left = NULL;
            else {
                TreeNode* leftNode = new TreeNode(stoi(ans));
                temp->left = leftNode;
                q.push(leftNode);
            }

            getline(ss , ans, ',');
             if(ans == "#") temp->right = NULL;
            else {
                TreeNode* rightNode = new TreeNode(stoi(ans));
                temp->right = rightNode;
                q.push(rightNode);
            }


        }
     return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));