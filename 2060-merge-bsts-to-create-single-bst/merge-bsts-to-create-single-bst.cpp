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