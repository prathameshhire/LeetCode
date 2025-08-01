class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;
    
        return parent[x] = find(parent[x]);
    }
    
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
    
        if (x_parent == y_parent) 
            return;
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int kruskal(vector<vector<int>> &vec) {
        int sum = 0;
        for (auto &temp : vec) {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v) {
                Union(parent_u, parent_v);
                sum+=wt;
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<int>> vec;
        parent.resize(V);
        rank.resize(V,0);
        for (int i = 0; i<V; i++) {
            parent[i] = i;
        }

        for (int i = 0; i<V; i++) {
            for (int j = 0; j<V; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1-x2) + abs(y1-y2);
                vec.push_back({i,j,d});

            }
        }
        auto comparator = [&] (vector<int> &vec1, vector<int> &vec2) {
            return vec1[2] < vec2[2];
        };

        sort(vec.begin(), vec.end(), comparator);

        return kruskal(vec);
    }
};