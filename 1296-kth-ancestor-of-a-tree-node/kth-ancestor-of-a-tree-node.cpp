class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG;

    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while ((1 << LOG) <= n)
            LOG++;

        up.assign(n, vector<int>(LOG, -1));

        // 2^0 = 1st ancestor
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }

        // Build 2^j ancestors
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j - 1] != -1)
                    up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {

        for (int j = 0; j < LOG; j++) {

            // If jth bit of k is set
            if (k & (1 << j)) {
                node = up[node][j];

                if (node == -1)
                    return -1;
            }
        }

        return node;
    }
};