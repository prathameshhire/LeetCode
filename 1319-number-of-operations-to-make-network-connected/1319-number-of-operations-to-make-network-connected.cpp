class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x == parent_y) return;
        if (rank[parent_x] > rank[parent_y]) parent[parent_y] = parent_x;
        else if (rank[parent_y] > rank[parent_x]) parent[parent_x] = parent_y;
        else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        rank.resize(n,1);
        parent.resize(n);
        for (int i = 0; i<n; i++) parent[i] = i;
        for (auto &vec : connections) {
            if (find(vec[0]) != find(vec[1])) {
                Union(vec[0],vec[1]);
                n--;
            }
        }
        return n-1;
    }
};