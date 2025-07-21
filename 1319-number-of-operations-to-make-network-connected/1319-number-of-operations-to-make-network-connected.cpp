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
        int extra = 0;
        for (int i = 0; i<n; i++) parent[i] = i;
        for (auto vec : connections) {
            int a = vec[0];
            int b = vec[1];
            if (find(a) == find(b)) extra++;
            else {
                Union(a,b);
            }
        }
        unordered_map<int, int> mp;
        for (auto val : parent) mp[find(val)]++;
        int nodes = mp.size();
        return nodes-1;
    }
};