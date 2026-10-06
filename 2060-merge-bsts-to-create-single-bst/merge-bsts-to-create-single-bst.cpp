class Solution {
public:

    unordered_map<int, TreeNode*> mp;
    int count = 0;

    bool dfs(TreeNode* root, long long low, long long high) {

        if (root == NULL)
            return true;

        // BST check
        if (root->val <= low || root->val >= high)
            return false;

        // If leaf, check whether another tree has this root
        if (!root->left && !root->right) {

            if (mp.count(root->val)) {

                TreeNode* newRoot = mp[root->val];

                // Attach children of that tree
                root->left = newRoot->left;
                root->right = newRoot->right;

                mp.erase(root->val);

                count++;
            }
        }

        return dfs(root->left, low, root->val) &&
               dfs(root->right, root->val, high);
    }


    TreeNode* canMerge(vector<TreeNode*>& trees) {

        int n = trees.size();

        // Store every tree by its root value
        for (TreeNode* t : trees) {
            mp[t->val] = t;
        }


        // Find values appearing as leaves
        unordered_set<int> leafValues;

        for (TreeNode* t : trees) {

            if (t->left)
                leafValues.insert(t->left->val);

            if (t->right)
                leafValues.insert(t->right->val);
        }


        // Find final root
        TreeNode* root = NULL;

        for (TreeNode* t : trees) {

            if (!leafValues.count(t->val)) {

                root = t;
                break;
            }
        }


        if (root == NULL)
            return NULL;


        // Final root itself should not be merged
        mp.erase(root->val);

        count = 1;


        // Merge everything in one traversal
        if (!dfs(root, LLONG_MIN, LLONG_MAX))
            return NULL;


        // Every tree must have been used
        if (count != n)
            return NULL;


        return root;
    }
};



//Approach 2 -> givea TLE 

// class Solution {
// public:

//     bool dfs(TreeNode* root, int target, TreeNode* newRoot) {

//         if (root == NULL)
//             return false;

//         // Only a LEAF can be replaced
//         if (!root->left && !root->right) {

//             if (root->val == target) {

//                 root->left = newRoot->left;
//                 root->right = newRoot->right;

//                 return true;
//             }

//             return false;
//         }

//         return dfs(root->left, target, newRoot) ||
//                dfs(root->right, target, newRoot);
//     }


//     bool isBST(TreeNode* root, long long low, long long high) {

//         if (root == NULL)
//             return true;

//         if (root->val <= low || root->val >= high)
//             return false;

//         return isBST(root->left, low, root->val) &&
//                isBST(root->right, root->val, high);
//     }


//     TreeNode* canMerge(vector<TreeNode*>& trees) {

//         // Find values which occur at leaves
//         unordered_set<int> leafValues;

//         for (TreeNode* t : trees) {

//             if (t->left)
//                 leafValues.insert(t->left->val);

//             if (t->right)
//                 leafValues.insert(t->right->val);
//         }


//         // Find the final root
//         TreeNode* root = NULL;

//         int rootIndex = -1;

//         for (int i = 0; i < trees.size(); i++) {

//             if (!leafValues.count(trees[i]->val)) {

//                 root = trees[i];
//                 rootIndex = i;

//                 break;
//             }
//         }


//         if (root == NULL)
//             return NULL;


//         vector<bool> used(trees.size(), false);

//         // FIX 1
//         used[rootIndex] = true;

//         int treesCount = 1;


//         bool changed = true;

//         while (changed) {

//             changed = false;

//             for (int j = 0; j < trees.size(); j++) {

//                 if (used[j])
//                     continue;

//                 if (dfs(root, trees[j]->val, trees[j])) {

//                     used[j] = true;

//                     treesCount++;

//                     changed = true;
//                 }
//             }
//         }


//         // Check that all trees were merged
//         // and final tree is a valid BST
//         if (treesCount == trees.size() &&
//             isBST(root, LLONG_MIN, LLONG_MAX)) {

//             return root;
//         }

//         // FIX 2
//         return NULL;
//     }
// };